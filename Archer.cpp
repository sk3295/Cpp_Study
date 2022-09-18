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
		PrintLine("��ó�� ��ų ��뿡 �����߽��ϴ�.");
	} else if (RandomRange(0.0f, 1.0f) > 0.7f) {
		result = target->TakeDamage(this, damageMax * RandomRange(1, 3));

		Print(target->name);
		PrintLine("���� �Ӱ��� ����ߴ�!");

		Print(target->name);
		Print("����");
		Print(ToString(result));
		PrintLine("�� �������� �Ծ���.");
	} else {
		PrintLine("��ó�� ��ų ��뿡 �����߽��ϴ�.");
	}

	return result;
}

int Archer::TakeDamage(class Character* attacker, int damage) {
	if (RandomRange(0.0f, 1.0f) < 0.3f) {
		PrintLine("��ó�� ������ ȸ���ϰ� �ݰ� �ߴ�!");
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