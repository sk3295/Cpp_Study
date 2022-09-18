#include "Actions.h"
#include "PrintFunctions.h"
#include "PlayerActions.h"
#include "GameData.h"
#include "Character.h"

std::vector<Action*> availableAction;

Action action_Attack		('a', "����", AttackCommand);
Action action_Skill			('s', "��ų", SkillCommand);
Action action_Defence		('d', "���", DefenceCommand);
Action action_Fill_Health	('f', "����", FillHealthCommand);

void AddAction(Action& target) { availableAction.push_back(&target); }
void ClearAction() { availableAction.clear(); }

void ImportCombatAction() {
	AddAction(action_Attack);
	if(player->cooldownCurrent <= 0) AddAction(action_Skill);

	AddAction(action_Defence);
	if(potionCount > 0) AddAction(action_Fill_Health);
}