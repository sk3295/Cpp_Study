#ifndef __GAME_DATA
#define __GAME_DATA

#include <random>

extern std::random_device randomMachine;
extern std::mt19937 twister;

int RandomRange(int min, int max);
float RandomRange(float min, float max);

extern class Character* player;
extern class Character* monster;

//������ ��
extern int turn;
//ų��
extern int killCount;
//���Ǽ�
extern int potionCount;

//���� ������ ����
extern bool gameRunning;

#endif
