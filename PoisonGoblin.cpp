#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void PoisonGoblin::AI() {
	Character* target = FindEnemy();
	if (poisonStack >= 4 && RandomRange(0.0f, 1.0f) < 0.4f) {
		Skill(target);
	}
	else {
		Attack(target);
	}

	if (poisonStack >= 2 && RandomRange(0.0f, 1.0f) < (-0.2f + (poisonStack * 0.178f))) {
		Skill(target);
	} else {
		Attack(target);
	}
}

int PoisonGoblin::Attack(Character* target, float multiplier) {
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
int  PoisonGoblin::Defence(class Character* target) {
	PrintLine("독 고블린은 나약한 팔을 방패 삼아 보지만 막을 수 없었다.");
}

void PoisonGoblin::TurnEnd() {
	Character* target = FindEnemy();
	
	int result = target->TakeDamage(this, poisonStack * 2);

	Print(target->name);
	Print("에게 독의 피해를 주고 있다.");

	Print(target->name);
	Print("에게");
	Print(ToString(result));
	PrintLine("피해!");
} 

void PoisonGoblin::OnMonsterSpawn() {
	poisonStack = 0;
}