#ifndef __GAME_DATA
#define __GAME_DATA

#include <random>

extern std::random_device randomMachine;
extern std::mt19937 twister;

int RandomRange(int min, int max);
float RandomRange(float min, float max);

extern class Character* player;
extern class Character* monster;

//진행한 턴
extern int turn;
//킬수
extern int killCount;
//포션수
extern int potionCount;

//게임 진행중 여부
extern bool gameRunning;

#endif
