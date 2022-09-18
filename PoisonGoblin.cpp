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
			PrintLine("���� ���� ������ �����ߴ�.");
		}
	}

	return result;
}
int  PoisonGoblin::Skill(class Character* target) {
	int result = 0;

	if (cooldownCurrent > 0 || manaCurrent < 35) {
		PrintLine("�� ����� ��ų ��뿡 �����߽��ϴ�.");
	} else {
		result = target->TakeDamage(this, poisonStack * 4);
		poisonStack = 0;
		Print(target->name);
		PrintLine("���� �����ִ� ���� �� ���� ��Ʈ����!");

		Print(target->name);
		Print("����");
		Print(ToString(result));
		PrintLine("�� �������� �Ծ���.");
	};

	return result;
}

int  PoisonGoblin::TakeDamage(class Character* attacker, int damage) {
	if (RandomRange(0.0f, 1.0f) < 0.25f) {
		PrintLine("�� ����� ������ ȸ���ߴ�!");
		return 0;
	} else {
		return Character::TakeDamage(attacker, damage);
	}
}
int  PoisonGoblin::Defence(class Character* target) {
	PrintLine("�� ����� ������ ���� ���� ��� ������ ���� �� ������.");
}

void PoisonGoblin::TurnEnd() {
	Character* target = FindEnemy();
	
	int result = target->TakeDamage(this, poisonStack * 2);

	Print(target->name);
	Print("���� ���� ���ظ� �ְ� �ִ�.");

	Print(target->name);
	Print("����");
	Print(ToString(result));
	PrintLine("����!");
} 

void PoisonGoblin::OnMonsterSpawn() {
	poisonStack = 0;
}