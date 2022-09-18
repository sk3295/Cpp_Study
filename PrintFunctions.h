#ifndef __PRINT_FUNCTIONS
#define __PRINT_FUNCTIONS
#include <stdio.h>

_inline char* ToString(int target)
{
	char buffer[10];
	sprintf_s(buffer, 10, "%d", target);
	return buffer;
}

void WaitNext();

//사용가능한 액션을 표시
void PrintAvailableAction();

//플레이어와 몬스터의 상태를 출력
void PrintStatus();

//프린트를 하고 줄바꿈 (속도 기본값 : 10)
void PrintLine(const char* text, int speed = 10);

//천천히 시간에 따라 출력 (속도 기본값 : 10)
void Print(const char* text, int speed = 10);

void ClearScreen();

enum Color {
	Color_Black,
	Color_Blue,
	Color_Green,
	Color_BrightBlue,
	Color_Red,
	Color_Purple,
	Color_Gold,
	Color_TextOrigin,
	Color_Grey,
	Color_Sky,
	Color_BrightGreen,
	Color_Mint,
	Color_Crimson,
	Color_Violet,
	Color_BrightYellow,
	Color_White,
};

#endif
