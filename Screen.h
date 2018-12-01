#pragma once
void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(int x, int y, const char* string);
void SetColor(unsigned short color);
void ScreenClearFunc();
void gotoxy(int x, int y);
void textcolor(int color_number);