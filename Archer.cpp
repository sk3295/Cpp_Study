#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void Archer::AI() {
	Character* target = FindEnemy();
}

int Archer::Attack(class Character* target, float multiplier) {
	int attackAmount = RandomRange(0.0f, 1.0f) < 0.7f ? 1 : 2;
	int result = 0;

	for (int i = 0; i < attackAmount; i++) {
		result += Character::Attack(target, multiplier);
	}
}
int Archer::Skill(class Character* target) {
}

int Archer::TakeDamage(class Character* attacker, int damage) {}
int Archer::Defence(class Character* target) {}
int Archer::Potion(class Character* target) {}

void Archer::TurnEnd() {}

void Archer::OnMonsterSpawn() {}