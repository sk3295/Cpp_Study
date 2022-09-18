#include "GameData.h"
#include "PrintFunctions.h"
#include "InputFunction.h"
#include "Actions.h"
#include "Character.h"

Character* player			= new Character("ฟ๋ป็", 100, 50, 10, 20);
Character* monster			= nullptr;
int  turn					= 0;
int  killCount				= 0;
int  potionCount			= 3;
bool gameRunning			= true;

void main() {
	SpawnMonster();

	while (gameRunning) {
		ClearScreen();			

		PrintStatus();			
		ImportCombatAction();	

		player->TurnStart();	

		PrintAvailableAction();	
		while (!PlayerAction());
		ClearAction();			

		player->TurnEnd();		
		WaitNext();				

		if (DeathCheck()) {						
			monster->TurnStart();	
			monster->AI();			
			monster->TurnEnd();		

			WaitNext();			

			DeathCheck();		
		};
	};
}