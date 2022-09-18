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
	PrintLine("�̹��� �ƹ��͵� ���� �ʾ�����, ���� �̻��� ������ ��� �����ߴ�.");
	PrintLine("(�̹��� ���ݷ��� 2�谡 �Ǿ���.)");
	damageMin *= 2;
	damageMax *= 2;
	return 1; 
}