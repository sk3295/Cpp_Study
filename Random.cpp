#include "GameData.h"

std::random_device randomMachine;
std::mt19937 twister( randomMachine() );	
											
int RandomRange(int min, int max)
{
	if (max <= min) { return min; };
	//                         최소 ~ 최대
	//                          0      7
	//                        0 1 2 3 4 5 6
	// 0 ~ 0.9999999           0 ~ 6.99999
	std::uniform_int<int> range(min, max + 1);

	return range(twister);
}

float RandomRange(float min, float max)
{
	if (max <= min) { return min; };
	std::uniform_real<float> range(min, max);
	return range(twister);
}