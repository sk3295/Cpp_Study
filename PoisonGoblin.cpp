#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void PoisonGoblin::AI() {}

int  PoisonGoblin::Attack(class Character* target, float multiplier = 1.0f) {
	int attackAmount = RandomRange(0.0f, 1.0f) < 0.7f ? 1 : 2;
	int result = 0;

	for (int i = 0; i < attackAmount; i++) {
		result += Character::Attack(target, multiplier);
		
		if (RandomRange(0.0f, 1.0f) < 0.8f) {
			++poisonStack;
			Print(target->name);
			PrintLine("에게 독이 퍼지기 시작했다.");
		}
	}

	return result;
}
int  PoisonGoblin::Skill(class Character* target) {
	int result = 0;

	if (cooldownCurrent > 0 || manaCurrent < 35) {
		PrintLine("독 고블린의 스킬 사용에 실패했습니다.");
	} else {
		result = target->TakeDamage(this, poisonStack * 4);
		poisonStack = 0;
		Print(target->name);
		PrintLine("에게 퍼져있던 독을 한 번에 터트린다!");

		Print(target->name);
		Print("에게");
		Print(ToString(result));
		PrintLine("의 데미지를 입었다.");
	};

	return result;
}

int  PoisonGoblin::TakeDamage(class Character* attacker, int damage) {
	if (RandomRange(0.0f, 1.0f) < 0.25f) {
		PrintLine("독 고블린은 공격을 회피했다!");
		return 0;
	} else {
		return Character::TakeDamage(attacker, damage);
	}
}
int  PoisonGoblin::Defence(class Character* target) {}

void PoisonGoblin::TurnEnd() {}

void PoisonGoblin::OnMonsterSpawn() {}