#include"headerFiles.h"


int CancelUI(RSV_node_ptr *head) {
	// 입력 ====================================================
	char inputId[100], Check[2] = { 0, };
	gotoxy(2, 1); printf("[예약정보입력] - [취소]");
	gotoxy(2, 3); printf("=================================================");
	gotoxy(2, 4); printf("ID 입력 : ");
	gotoxy(2, 5); printf("=================================================");
	gotoxy(12, 4); scanf("%[^\n]", inputId); 
	while (getchar() != '\n');
	// 조회 ===================================================
	RSV_node_ptr temp = RSV_TREE_SEARCH(*head, inputId);
	char nKey;
	int MoveBar;
	if (temp != Sentinel) {
		gotoxy(2, 5); printf("====================================================================================================================");
		gotoxy(2, 6); printf("ID"); gotoxy(16, 6); printf("출발"); gotoxy(23, 6); printf("도착"); gotoxy(30, 6); printf("스케쥴 정보");
		ShowReserveInfo(temp, 2, 8);
		
		gotoxy(50, 18); printf("취소하시겠습니까? (Y/N)");
		char nKey;
		scanf("%c", &nKey);
		if (nKey == 'y' || nKey == 'Y') {
			RSV_RB_DELETE(head, temp->Key);
			gotoxy(50, 20); printf("취소되었습니다.");
			Sleep(3000);
		}
		else if (nKey == 'n' || nKey == 'N') {

		}
		else {

		}
	}
	else {
		gotoxy(2, 7); printf("<< 해당 정보 없음 >>");
		gotoxy(2, 10); printf("메인화면 돌아가려면 enter 입력");
		while (getchar() != '\n');
	}
	//while (getchar() != '\n');

	return 1;
}