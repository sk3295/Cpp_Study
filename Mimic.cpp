#include "Character.h"
#include "PrintFunctions.h"
#include "GameData.h"

void Mimic::AI() {
	if (passTurn > 0) {
		Defence(FindEnemy());
		--passTurn;
	} else {
		Character* enemy = FindEnemy();

		if (enemy->healthCurrent <= damageMax || healthCurrent <= enemy->damageMax || RandomRange(0.0f, 1.0f) < 0.65f) {
			Attack(enemy);
		} else {
			Skill(enemy);
		}

		passTurn = 2;
	};
}

int Mimic::Skill(class Character* target) {
	PrintLine("미믹은 아무것도 하지 않았지만, 뭔가 이상한 느낌이 들기 시작했다.");
	PrintLine("(미믹의 공격력이 2배가 되었다.)");
	damageMin *= 2;
	damageMax *= 2;
	return 1; 
}