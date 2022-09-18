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
	//   ����      ����
	//   0000     0000
	//  128 64 32 16 8 4 2 1
	SetConsoleTextAttribute(consoleHandle, textColor + (backgroundColor << 4));
}

void WaitNext()
{
	cout << "[���͸� ���� ��������]" << endl;
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
		//                         ����� ǥ��ĭ�� ����º��� ���� ���
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
	//  0 ~ 14                  -  2 (�ּҰ���ŭ ���ֱ�)
	//  0 ~ 1					/ 14 (�ִ밪��ŭ �����ֱ�)

	//  (2 - 2)  / 14  =  0 / 14  = 0
	//  (8 - 2)  / 14  =  6 / 14  = 0.43
	//  (12 - 2) / 14  = 10 / 14  = 0.71
	//  (16 - 2) / 14  = 14 / 14  = 1

	//  2 ~ 16     37 ~ 82
	// [-2] [/14]
	//  0 ~ 1
	//             45�� 
	//  0 ~ 45	   *45
	//			   37�� �ּ�
	// 37 ~ 82     +37

	//       [Normalize]
	// 100 * 0.7 = 70;

	//�ø�	 Ceil
	//�ݿø� Round
	//����	Floor
	PrintBar(wantColor, (int)ceilf(wantRate * 10));
}

void PrintCharacter(Character* target)
{
	cout << target->name << endl;

	// [ 1 / 10 ] 10%  0.1f
	// [ 8 / 10 ] 80%  0.8f
	// ���� / ���� = ���� => 1 or 0!
	// �Ǽ� / ���� = �Ǽ�
	// ���� / �Ǽ� = �Ǽ�
	// �Ǽ� / �Ǽ� = �Ǽ�
	PrintBar(Color_Red, (float)target->healthCurrent / target->healthMax);
	PrintBar(Color_Sky, (float)target->manaCurrent / target->manaMax);
	cout << "(��Ÿ�� : " << target->cooldownCurrent << ")" << endl;
}

//�׼��� �ϳ� ����Ʈ
void PrintAction(Action* target)
{
	cout << "[";
	cout << target->GetUpperKey();
	cout << ": ";
	cout << target->GetExplain();
	cout << "]";
}

//��밡���� �׼��� ����Ʈ
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
	cout << "���� ���� : [" << potionCount << "]"   << endl;
	cout << "óġ Ƚ�� : [" << killCount   << "]"   << endl;
	cout << "====================================" << endl;
}

void PrintLine(const char* text, int speed)
{
	Print(text, speed);  //���� ������
	cout << endl; //����
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