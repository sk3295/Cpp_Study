#include "PlayerActions.h"
#include "Character.h"
#include "GameData.h"

bool AttackCommand() {
	player->Attack(monster);
	return true;
}
bool SkillCommand() {
	return player->Skill(monster);
}
bool DefenceCommand() {
	player->Defence(monster);
	return true;
}
bool FillHealthCommand() {
	if (potionCount <= 0) return false;
	int result = player->Potion(player);
	if (!result) { return false; };

	--potionCount;

	return true;
}