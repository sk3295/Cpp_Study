#include <iostream>
#include <Windows.h>
#include "Character.h"
#include "GameData.h"
#include "Actions.h"
#include "PrintFunctions.h"
using namespace std;

void SetColor(Color textColor, Color backgroundColor = Color_Black)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//   바탕      글자
	//   0000     0000
	//  128 64 32 16 8 4 2 1
	SetConsoleTextAttribute(consoleHandle, textColor + (backgroundColor << 4));
}

void WaitNext()
{
	cout << "[엔터를 눌러 다음으로]" << endl;
	char buffer[100];			
	fgets(buffer, 100, stdin);	

	return;
}

void ClearScreen()
{
	system("cls");
}

void PrintBar(Color wantColor, int wantRate)
{
	cout << "[";
	for (int i = 0; i < 10; i++)
	{
		//                         생명력 표시칸이 생명력보다 작은 경우
		//                                          4
		//                                                  0 1 2 3
		//                                          7
		//                                                  0 1 2 3 4 5 6
		SetColor(Color_TextOrigin, i < wantRate ? wantColor : Color_Black);
		cout << " ";
	};
	SetColor(Color_TextOrigin);
	cout << "]";
}

//                           
void PrintBar(Color wantColor, float wantRate)
{
	//  2 ~ 16     0 ~ 1
	//  0 ~ 14                  -  2 (최소값만큼 빼주기)
	//  0 ~ 1					/ 14 (최대값만큼 나눠주기)

	//  (2 - 2)  / 14  =  0 / 14  = 0
	//  (8 - 2)  / 14  =  6 / 14  = 0.43
	//  (12 - 2) / 14  = 10 / 14  = 0.71
	//  (16 - 2) / 14  = 14 / 14  = 1

	//  2 ~ 16     37 ~ 82
	// [-2] [/14]
	//  0 ~ 1
	//             45의 
	//  0 ~ 45	   *45
	//			   37이 최소
	// 37 ~ 82     +37

	//       [Normalize]
	// 100 * 0.7 = 70;

	//올림	 Ceil
	//반올림 Round
	//버림	Floor
	PrintBar(wantColor, (int)ceilf(wantRate * 10));
}

void PrintCharacter(Character* target)
{
	cout << target->name << endl;

	// [ 1 / 10 ] 10%  0.1f
	// [ 8 / 10 ] 80%  0.8f
	// 정수 / 정수 = 정수 => 1 or 0!
	// 실수 / 정수 = 실수
	// 정수 / 실수 = 실수
	// 실수 / 실수 = 실수
	PrintBar(Color_Red, (float)target->healthCurrent / target->healthMax);
	PrintBar(Color_Sky, (float)target->manaCurrent / target->manaMax);
	cout << "(쿨타임 : " << target->cooldownCurrent << ")" << endl;
}

//액션을 하나 프린트
void PrintAction(Action* target)
{
	cout << "[";
	cout << target->GetUpperKey();
	cout << ": ";
	cout << target->GetExplain();
	cout << "]";
}

//사용가능한 액션을 프린트
void PrintAvailableAction()
{
	// for (Action* current : availableAction);
	for (int i = 0; i < availableAction.size(); i++)
	{
		PrintAction(availableAction[i]);
	};
	cout << endl;
}

void PrintStatus()
{
	cout << "====================================" << endl;
	PrintCharacter(player);
	cout << "------------------------------------" << endl;
	PrintCharacter(monster);
	cout << "====================================" << endl;
	cout << "남은 포션 : [" << potionCount << "]"   << endl;
	cout << "처치 횟수 : [" << killCount   << "]"   << endl;
	cout << "====================================" << endl;
}

void PrintLine(const char* text, int speed)
{
	Print(text, speed);  //원본 돌리기
	cout << endl; //엔터
}
void Print(const char* text, int speed)
{
	for (int i = 0; text[i] != NULL; i++)
	{
		putchar(text[i]);
		Sleep(speed);
	};
	//cout << text;

}