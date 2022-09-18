#include "Character.h"
#include "GameData.h"
#include "PrintFunctions.h"

void SpawnMonster() {
	int random = RandomRange(0, 1);

	switch (random) {
	case 0: monster = new Mimic(); break;
	default: monster = new PoisonGoblin(); break;
	};
}

bool DeathCheck() {
	if (player->healthCurrent <= 0) { gameRunning = false; };
	if (monster->healthCurrent <= 0) {
		++killCount;				
		player->OnMonsterKill();	

		SpawnMonster();				

		player->OnMonsterSpawn();	
		return false;				
	};

	return gameRunning;
}


Character* Character::FindEnemy() { return this == player ? monster : player; };

void Character::AI() {
	Character* target = FindEnemy();

	if (Skill(target) == false) {

		if (RandomRange(0.0f, 1.0f) < 0.8f) {
			Attack(target);
		} else {
			Defence(target);
		};
	}
}


void Character::TurnEnd() {
	if(cooldownCurrent > 0) --cooldownCurrent;

	manaCurrent += 10;
	if (manaCurrent > manaMax) manaCurrent = manaMax;
};

void Character::TurnStart() { currentDefence = false; };
void Character::OnMonsterSpawn(){};
void Character::OnMonsterKill() {};
void Character::Die() {};

int Character::Attack(Character* target, float multiplier) {
	int result = target->TakeDamage(this, (int)(RandomRange(damageMin, damageMax) * multiplier));

	Print(name);
	Print("은(는) ");
	Print(target->name);
	Print("에게 ");
	Print( ToString(result) );
	Print("의 데미지를 주었다!\n");
	return result;
};

int Character::Skill(Character* target) {
	int result = 0;

	if (cooldownCurrent > 0) {
		if(this == player) PrintLine("아직 준비중입니다.");
	} else if (manaCurrent >= 30) {
		cooldownCurrent = 2;
		manaCurrent -= 30;

		Print(name);
		PrintLine("의 두 번 치기!");

		result += Attack(target);
		result += Attack(target);

		Print("총 ");
		Print(ToString(result));
		PrintLine("의 데미지를 주었다!");

		if (result == 0) result = 1;
	} else { if (this == player) PrintLine("마나가 부족합니다."); };
	
	return result;
};

int Character::Defence(Character* target) {
	currentDefence = true;
	
	Print(name);
	PrintLine("은(는) 방어를 하기로 했다!");

	return 1;
};
int Character::Potion(Character* target) {
	int result = target->TakeHeal(this, 100);//target->healthMax);

	if (result) {
		Print(name);
		Print("은(는) 포션을 마시고 ");
		Print(ToString(result));
		PrintLine("만큼 회복했다!");
	}
	else {
		PrintLine("포션을 마실 수 없었습니다.");
	};

	return result;							
};



int Character::TakeDamage(Character* attacker, int damage) {
	int result = damage;

	if (currentDefence) result *= 0.5f;
	if (result > healthCurrent) result = healthCurrent;

	healthCurrent -= result;

	if (result > 0 && healthCurrent <= 0) { Die(); }

	return result;
};

int Character::TakeHeal(Character* healer, int heal) {
	int result = heal;

	int maximumHeal = healthMax - healthCurrent;
	if (result > maximumHeal) result = maximumHeal;

	healthCurrent += result;

	return result;
};