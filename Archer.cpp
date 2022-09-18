#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void Archer::AI() {
	Character* target = FindEnemy();
}

int Archer::Attack(Character* target, float multiplier) {
	int attackAmount = RandomRange(0.0f, 1.0f) < 0.7f ? 1 : 2;
	int result = 0;

	for (int i = 0; i < attackAmount; i++) {
		result += Character::Attack(target, multiplier);
	}
}
int Archer::Skill(class Character* target) {
	int result = 0;

	if (cooldownCurrent > 0 || manaCurrent < 30) {
		PrintLine("아처의 스킬 사용에 실패했습니다.");
	} else if (RandomRange(0.0f, 1.0f) > 0.7f) {
		result = target->TakeDamage(this, damageMax * RandomRange(1, 3));

		Print(target->name);
		PrintLine("에게 속공을 사용했다!");

		Print(target->name);
		Print("에게");
		Print(ToString(result));
		PrintLine("의 데미지를 입었다.");
	} else {
		PrintLine("아처의 스킬 사용에 실패했습니다.");
	}

	return result;
}

int Archer::TakeDamage(class Character* attacker, int damage) {
	if (RandomRange(0.0f, 1.0f) < 0.3f) {
		PrintLine("아처는 공격을 회피하고 반격 했다!");
		return 0;
	}
	else {
		return Character::TakeDamage(attacker, damage);
	}
}
int Archer::Defence(class Character* target) {}
int Archer::Potion(class Character* target) {}

void Archer::TurnEnd() {}

void Archer::OnMonsterSpawn() {}