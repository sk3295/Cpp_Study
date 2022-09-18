#ifndef __CHARACTER
#define __CHARACTER

void SpawnMonster();
bool DeathCheck();

class Character
{
public:
	char* name;
	int healthCurrent, healthMax;
	int manaCurrent, manaMax;
	int damageMin, damageMax;
	int cooldownCurrent;
	bool currentDefence = false; 

	Character(const char* wantName, int wantHealth, int wantMana, int wantDamMin, int wantDamMax, int startCooldown = 0)
	{
		name = (char*)wantName;
		healthCurrent	= healthMax	= wantHealth;
		manaCurrent		= manaMax	= wantMana;
		damageMin = wantDamMin;
		damageMax = wantDamMax;
		cooldownCurrent = startCooldown;
	}

	class Character* FindEnemy();

	virtual void AI();				

	virtual void TurnEnd();			
	virtual void TurnStart();			
	virtual void OnMonsterSpawn();		
	virtual void OnMonsterKill();		
	virtual void Die();					

	virtual int  Attack (class Character* target, float multiplier = 1.0f);	
	virtual int  Skill  (class Character* target);					
	virtual int  Defence(class Character* target);					
	virtual int  Potion (class Character* target);				
	virtual int  TakeDamage(class Character* attacker, int damage);
	virtual int  TakeHeal(class Character*  healer, int heal);		
};

class Mimic : public Character {
	int passTurn = 2;
public:
	Mimic() : Character("미믹", 60, 30, 15, 25) { Defence(FindEnemy()); };

	void AI();												
	int  Skill(class Character* target);				
};

class PoisonGoblin : public Character {
	int poisonStack = 0;

public:
	PoisonGoblin() : Character("독 고블린", 50, 40, 5, 8) {

	}

	void AI();

	int  Attack(class Character* target, float multiplier = 1.0f);
	int  Skill(class Character* target);
	
	int  TakeDamage(class Character* attacker, int damage);
	int  Defence(class Character* target);
	
	void TurnEnd();
	
	void OnMonsterSpawn();
};

class Archer : public Character {
	int concealmentState = 0;
public:
	Archer() : Character("아처", 70, 50, 20, 40) {

	}

	void AI();

	int  Attack(class Character* target, float multiplier = 1.0f);
	int  Skill(class Character* target);

	int  TakeDamage(class Character* attacker, int damage);
	int  Defence(class Character* target);
	int  Potion(class Character* target);

	void TurnEnd();

	void OnMonsterSpawn();
};

#endif