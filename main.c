#include"headerFiles.h"

/*
 * Created by SKKU_ALGO Team5 on 2018.11.18
*/

int main(void) {
	// INIT ======================================
	graph_ptr gp;
	HT_MakeSentinel();
	MakeSentinel();
	GraphInit(&gp);
	RSV_node_ptr ReserveHead = RSV_MakeRBT();

	int nKey, MoveBar;
	ScreenInit();
	init(&MoveBar); 
	
	while (1) {
		switch (Stage) {
		case RESERVATION:
			ScreenRelease(); ScreenClearFunc();
			ReservationUI(gp, &ReserveHead);
			Stage = MAIN;
			ScreenInit();
			break;
		case CHECK:
			ScreenRelease(); ScreenClearFunc();
			CheckUI(&ReserveHead);
			Stage = MAIN;
			ScreenInit();
			break;
		case CANCEL:
			ScreenRelease(); ScreenClearFunc();
			CancelUI(&ReserveHead);
			Stage = MAIN;
			ScreenInit(); 
			break;
		case CHECKALL:
			ScreenRelease(); ScreenClearFunc();
			CheckAllUI(ReserveHead);
			Stage = MAIN;
			ScreenInit(); // Screen restart
			while (getchar() != '\n');
			break;
		default: // MAIN 화면
			if (_kbhit()) {
				nKey = _getch();
				if (nKey == 13) { // Main화면에서 enter 입력시 MoveBar가 가르키고 있는 Stage로 진입
					Stage = MoveBar - 11;
				}
				if (nKey == 224) { // Main화면에서 방향키를 통해 MoveBar를 움직이는 역할
					nKey = _getch();
					switch (nKey) {
					case UP:
						MoveBar--;
						break;
					case DOWN:
						MoveBar++;
						break;
					case LEFT: // 뒤로가기
						Stage = MAIN;
						break;
					case RIGHT:
						break;
					}
				}
			}
			break;
		}
		Render(&MoveBar);  // 화면출력
	}
	ScreenRelease();
	return 0;
}


