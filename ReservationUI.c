#include"headerFiles.h"

void ShowTempInfo(hotel_site_ptr head, int StartPos, int DestPos, int InputBudget){
	int IdxPos = 5;
	int IdyPos = 18;
	hotel_site_ptr temp = head;
	int DaySum = 0;
	int CostSum = 0;
	//Path
	gotoxy(16, IdyPos); printf("S-%d", temp->CityNum);
	gotoxy(30, IdyPos + 1); printf("[���]\t");
	while (temp != NULL) {
		printf("S-%d\t", temp->CityNum);
		if (temp->next == NULL) {
			gotoxy(23, IdyPos); printf("S-%d", temp->CityNum);
			//CostSum = InputBudget - temp->Budget;
			CostSum += temp->Budget; // ���� ���� ??
		}
		temp = temp->next;
	}
	temp = head;
	gotoxy(30, IdyPos + 3); printf("[ȣ��]\t");
	while (temp != NULL) {
		printf("H-%d\t", temp->Hotel);
		temp = temp->next;
	}
	
	temp = head;
	gotoxy(30, IdyPos + 5); printf("[�Ⱓ]\t");
	while (temp != NULL) {
		printf("%d\t", temp->Day);
		DaySum += temp->Day;
		temp = temp->next;
	}
	gotoxy(82, IdyPos + 6); printf("\t\t\t[�� �Ⱓ] : %d", DaySum);
	gotoxy(82, IdyPos + 7); printf("\t\t\t[�ܾ�] : %d", CostSum);
	gotoxy(1, IdyPos + 8); printf("---------------------------------------------------------------------------------------------------------------------");

}

int askConfirmUI() {
	gotoxy(50, 28); printf("�����Ͻðڽ��ϱ�? (Y/N)");
	char nKey;
	scanf("%c", &nKey);
	if (nKey == 'y' || nKey == 'Y')
		return 1;
	else
		return 0;
}

void ReservationUI(graph_ptr gp, RSV_node_ptr *ReserveHead) {
	gotoxy(3, 1); printf("[�����ϱ�] - "); textcolor(10); printf("[�����Է�]"); textcolor(15); printf(" - [Ȯ��] ");
	gotoxy(3, 3); printf("=================================================");
	gotoxy(3, 5); printf("ID : ");
	gotoxy(3, 7); printf("����� : ");
	gotoxy(3, 9); printf("������ : ");
	gotoxy(3, 11); printf("��  �� : ");
	gotoxy(3, 13); printf("��  �� : ");
	gotoxy(2, 17); printf("==============================================================");

	int StartPos, DestPos;
	char id[50];
	int Period;
	int budget;

	ReservInput(&StartPos, &DestPos, id, &Period, &budget);
	node_ptr ShortestPath = Dijkstra(gp, StartPos, DestPos);
	hotel_site_ptr Data;
	if (ShortestPath != NULL) {
		Data = HS_MATCH(ShortestPath, gp, budget, Period);
		if (Data != NULL) {
			gotoxy(2, 15); printf("====================================================================================================================");
			gotoxy(2, 16); printf("********"); gotoxy(16, 16); printf("���"); gotoxy(23,16); printf("����"); gotoxy(30, 16); printf("������ ����");
			ShowTempInfo(Data, StartPos, DestPos, budget);
			if (askConfirmUI()) {
				RSV_RB_INSERT(ReserveHead, id, Data, budget);
				gotoxy(50, 29); printf("<<����Ϸ�>>");
				Sleep(5000);
			}
		}
		else {
			gotoxy(10, 20); printf("<<������� �ʰ�>>");
			Sleep(5000);
		}
	}
	else { // ���� ���
		gotoxy(10, 20); printf("<<��ξ���>>");
		Sleep(5000);
	}
	
}

void ReservInput(int *StartPos, int *DestPos, char *id, int *Period, int *budget) {
	gotoxy(12, 5); fgets(id, 20, stdin); strtok(id, "\n");
	gotoxy(12, 7); scanf("%d", StartPos);
	gotoxy(12, 9); scanf("%d", DestPos);
	gotoxy(12, 11); scanf("%d", Period);
	while (getchar() != '\n');
	gotoxy(12, 13); scanf("%d", budget);
	while (getchar() != '\n');
}
