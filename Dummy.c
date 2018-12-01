#include"headerFiles.h"

void DummyTest(graph_ptr gp, RSV_node_ptr *ReserveHead) {
	
	char ID[30] = "Eirc8260";
	int StartPos, DestPos, Period, Budget;

	// Case 1
	StartPos = 10;
	DestPos = 18;
	Period = 10;
	Budget = 5000;
	node_ptr ShortestPath = Dijkstra(gp, StartPos, DestPos);
	hotel_site_ptr Data;
	if (ShortestPath != NULL) { // 경로가 존재하는 경우
		Data = HS_MATCH(ShortestPath, gp, Budget, Period);
		if (Data != NULL) {
			RSV_RB_INSERT(ReserveHead, ID, Data, Budget);
		}
	}

	// Case 2
	strcpy(ID, "Hotoyoi");
	StartPos = 30;
	DestPos = 28;
	Period = 5;
	Budget = 5000;
	ShortestPath = Dijkstra(gp, StartPos, DestPos);
	if (ShortestPath != NULL) { // 경로가 존재하는 경우
		Data = HS_MATCH(ShortestPath, gp, Budget, Period);
		if (Data != NULL) {
			RSV_RB_INSERT(ReserveHead, ID, Data, Budget);
		}
	}

	// Case 3
	strcpy(ID, "Yeoing");
	StartPos = 99;
	DestPos = 12;
	Period = 12;
	Budget = 5000;
	ShortestPath = Dijkstra(gp, StartPos, DestPos);
	if (ShortestPath != NULL) { // 경로가 존재하는 경우
		Data = HS_MATCH(ShortestPath, gp, Budget, Period);
		if (Data != NULL) {
			RSV_RB_INSERT(ReserveHead, ID, Data, Budget);
		}
	}
	// Case 4
	strcpy(ID, "Moondo");
	StartPos = 92;
	DestPos = 4;
	Period = 12;
	Budget = 5000;
	ShortestPath = Dijkstra(gp, StartPos, DestPos);
	if (ShortestPath != NULL) { // 경로가 존재하는 경우
		Data = HS_MATCH(ShortestPath, gp, Budget, Period);
		if (Data != NULL) {
			RSV_RB_INSERT(ReserveHead, ID, Data, Budget);
		}
	}

	// Case 5
	strcpy(ID, "KKE");
	StartPos = 9;
	DestPos = 12;
	Period = 12;
	Budget = 5000;
	ShortestPath = Dijkstra(gp, StartPos, DestPos);
	if (ShortestPath != NULL) { // 경로가 존재하는 경우
		Data = HS_MATCH(ShortestPath, gp, Budget, Period);
		if (Data != NULL) {
			RSV_RB_INSERT(ReserveHead, ID, Data, Budget);
		}
	}
}

