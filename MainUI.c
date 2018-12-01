#include"headerFiles.h"
void MainUI() {
	ScreenPrint(4, 2, "---------------------------------------------");
	ScreenPrint(7, 4, "Tour Reservation and Scheduling System");
	ScreenPrint(8, 6, "- gkgkgkgk -");
	ScreenPrint(4, 8, "---------------------------------------------");
	ScreenPrint(4, 10, "[ M E N U ]");
	ScreenPrint(4, 12, "1. 예약하기");
	ScreenPrint(4, 13, "2. 예약확인");
	ScreenPrint(4, 14, "3. 예약취소");
	ScreenPrint(4, 15, "4. 모든 예약현황 확인");
	ScreenPrint(4, 26, "Copyright(c) 2018 Team5. all rights reserved. ");
	ScreenPrint(4, 28, "---------------------------------------------");
}

void init(int *MoveBar) { // 시스템 초기화 단계
	Stage = MAIN;
	*MoveBar = 12;

	// RB 초기화 ===========================================
	HT_MakeSentinel();


	// 그래프 초기화 =========================================



}

void Render(int *MoveBar) {

	ScreenClear();
	switch (Stage) {
	case MAIN:
		MainUI();
		SelectBAR(*MoveBar);
		break;
	case RESERVATION:
		break;
	case CHECK:
		break;
	case CANCEL:
		break;
	case CHECKALL:
		break;
	}

	ScreenFlipping();
}

void SelectBAR(int Move) {
	ScreenPrint(2, Move, "▶");
}