#include"headerFiles.h"

void GraphInit(graph_ptr *gp) {
	*gp = (graph_ptr)malloc(sizeof(Graph));
	(*gp)->numE = EdgeNum;
	(*gp)->numV = VertexNum;
	
	CityInit(*gp); // to update 1) 100 hotel info per each site,  2) preferences per each site

	// Make adjList
	for (int i = 0; i < VertexNum; i++) {
		(*gp)->adjList[i] = NULL; // not using Dummy node
	}

	// Make Graph with 100 sites and 300 routes
	int fromV, toV, weight;
	srand(time(NULL));
	for (int i = 0; i < EdgeNum; i++) {
		fromV = rand() % VertexNum;
		toV = rand() % VertexNum;
		weight = (rand() % Weight_OFFSET) + 1;
		while (fromV == toV) // not duplicated
			toV = rand() % VertexNum;
		AddEdge(*gp, fromV, toV, weight);

	}

}

void AddEdge(graph_ptr gp, int fromV, int toV, int weight) {
	//direct
	node_ptr newNode = MakeNode(toV, weight);
	if (gp->adjList[fromV] == NULL) {
		gp->adjList[fromV] = newNode;
	}
	else { // adjList Insert : O(1)
		newNode->next = gp->adjList[fromV];
		gp->adjList[fromV] = newNode;
	}
	/*
	newNode = MakeNode(fromV, weight);
	if (gp->adjList[toV] == NULL) {
		gp->adjList[toV] = newNode;
	}
	else { // adjList Insert : O(1)
		newNode->next = gp->adjList[toV];
		gp->adjList[toV] = newNode;
	}
	*/
}


void ShowGraph(graph_ptr gp) {
	node_ptr temp;
	for (int i = 0; i < VertexNum; i++) {
		temp = gp->adjList[i];
		printf("[ %d ] : ", i);
		while (temp) {
			printf("(%d, %d) - ", temp->CityNum, temp->Weight);
			temp = temp->next;
		}
		puts(" ");
	}


}

void CityInit(graph_ptr gp) {
	srand(time(NULL));
	int preference; // 0 ~ 5

	// 1) init preference ========================
	for (int i = 0; i < VertexNum; i++) {
		preference = rand() % 6;
		gp->CityInfo[i].perference = preference;
	}

	// 2) init hotel info
	short PriceFlag[1001] = { 0, };
	int price;
	for (int i = 0; i < VertexNum; i++) {
		gp->CityInfo[i].Hotel = HT_MakeRBT();
		for (int j = 0; j < HotelNum; j++) {
			price = (rand() % 1000) + 1;
			while (PriceFlag[price]) { // 호텔 가격 범위 1 ~ 1000
				price = (rand() % 1000) + 1;
			}
			PriceFlag[price] = 1;
			gp->CityInfo[i].Hotel;
			HT_RB_INSERT(&(gp->CityInfo[i].Hotel), price, j);
		}
		memset(PriceFlag, 0, sizeof(PriceFlag)); // ? 
	}


}

void Inorder(HT_RBnode_ptr head) {
	if (head != HT_Sentinel) {
		Inorder(head->left);
		printf("%d %d\n", head->Key, head->Hotel_Num);
		Inorder(head->right);
	}
}


void ShowHotelInfo(graph_ptr gp, int CityNum) {
	HT_RBnode_ptr temp = getAllHotelinfo(gp, CityNum);
	Inorder(temp);
}

HT_RBnode_ptr getAllHotelinfo(graph_ptr gp, int CityNum) {
	return gp->CityInfo[CityNum].Hotel;
}


// ================================================

node_ptr MakeNode(int toV, int weight) {
	node_ptr newNode = (node_ptr)malloc(sizeof(HT_RBNode));
	newNode->CityNum = toV;
	newNode->next = NULL;
	newNode->Weight = weight;
	return newNode;
}

typedef struct PathNode {
	int CityNum;
	int Weight;
}PathNode;

node_ptr Dijkstra(graph_ptr gp, int fromV, int toV) {
	// Queue
	int Queue[10000] = { 0, };
	int Path[VertexNum]; // Path[toV] = fromV
	int Stack[VertexNum];
	int Top = -1;
	memset(Path, -1, sizeof(Path));

	int front = -1;
	int rear = -1;

	int Distance[VertexNum];
	for (int i = 0; i < VertexNum; i++) {
		Distance[i] = INT_MAX;
	}
	Distance[fromV] = 0;

	Queue[++rear] = fromV; // Q push
	int dest, weight;
	node_ptr temp;
	while (front != rear) { // if Q is empty
		dest = Queue[++front]; // Q pop
		temp = gp->adjList[dest];
		while (temp) {
			if (Distance[temp->CityNum] > Distance[dest] + temp->Weight) {
				Distance[temp->CityNum] = Distance[dest] + temp->Weight;
				Queue[++rear] = temp->CityNum;

				Path[temp->CityNum] = dest;

			}
			temp = temp->next;
		}
	}
	if (Distance[toV] == INT_MAX)
		return NULL; // 경로가 존재하지 않는다면

	int from = Path[toV];

	Stack[++Top] = toV;
	while (from!= -1) { 
		Stack[++Top] = from; 
		from = Path[from];
	}

	//node_ptr RtrNode = MakeNode(fromV, -1);
	node_ptr RtrNode = NULL;
	node_ptr AddNode;
	// 10 - 82
	// 10 - 89 - 18 - 44 - 3 - 82
	int target, targetWeight;
	while (Top != -1) {
		//printf("%d - ", Stack[Top]);
		target = Stack[Top--];
		AddNode = MakeNode(target, -1);
		temp = RtrNode;
		if (RtrNode == NULL) {
			RtrNode = AddNode;
		}
		else {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = AddNode;
		}
	}
	puts(" ");
	temp = RtrNode->next;
	int Tstart, Tdest, Tweight;
	Tstart = fromV;
	node_ptr temp2;
	while (temp != NULL) {
		Tweight = INT_MAX;
		temp2 = gp->adjList[fromV];
		while (temp2 != NULL) {
			if (temp2->CityNum == temp->CityNum) {
				if(Tweight > temp2->Weight)
					Tweight = temp2->Weight;
			}
			temp2 = temp2->next;
		}
		temp->Weight = Tweight;
		fromV = temp->CityNum;
		temp = temp->next;
	}
	temp2 = RtrNode;
	/*
	while (temp2 != NULL) {
		printf("(%d, %d) = ", temp2->CityNum, temp2->Weight);
		temp2 = temp2->next;
	}
	*/
	puts("  ");
	return RtrNode;
}
