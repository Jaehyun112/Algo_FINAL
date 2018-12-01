#pragma once

#define VertexNum 100
#define EdgeNum 300
#define HotelNum 100
#define Weight_OFFSET 100

typedef struct NODE* node_ptr;
typedef struct NODE {
	int CityNum;
	int Weight; // = Distance
	node_ptr next;
}Node;


typedef struct CITY {
	int CityNum;
	int perference;
	HT_RBnode_ptr Hotel;
}CITY;

typedef struct _GRAPH *graph_ptr;
typedef struct _GRAPH {
	int numV; // 정점의 수
	int numE; // 간선의 수
	CITY CityInfo[VertexNum];
	node_ptr adjList[VertexNum];
}Graph;


void GraphInit(graph_ptr *gp);
node_ptr MakeNode(int toV, int weight);
void AddEdge(graph_ptr gp, int fromV, int toV, int weight);

void CityInit(graph_ptr gp);
HT_RBnode_ptr getAllHotelinfo(graph_ptr gp, int CityNum);
void ShowHotelInfo(graph_ptr gp, int CityNum);

void ShowGraph(graph_ptr gp);
node_ptr Dijkstra(graph_ptr gp, int fromV, int toV);