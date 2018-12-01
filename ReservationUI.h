#pragma once
#include"Graph.h"
#include"RSV_RBT.h"

void ReservationUI(graph_ptr gp, RSV_node_ptr *ReserveHead);
void ReservInput(char *StartPos, char *DestPos, char *id, int *Period, int *budget);


