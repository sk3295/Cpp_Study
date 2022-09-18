#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void PoisonGoblin::AI() {}

int  PoisonGoblin::Attack(class Character* target, float multiplier = 1.0f) {
	int attackAmount = RandomRange(0.0f, 1.0f) < 0.7f ? 1 : 2;

	for (int i = 0; i < attackAmount; i++) {
		result += Character::Attack(target, multiplier);
		
		if (RandomRange(0.0f, 1.0f) < 0.8f) {
			++poisonStack;
			Print(target->name);
			PrintLine("에게 독이 퍼지기 시작했다.");
		}
	}
}
int  PoisonGoblin::Skill(class Character* target) {}

int  PoisonGoblin::TakeDamage(class Character* attacker, int damage) {}
int  PoisonGoblin::Defence(class Character* target) {}

void PoisonGoblin::TurnEnd() {}

void PoisonGoblin::OnMonsterSpawn() {}