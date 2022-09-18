#include "Actions.h"
#include <conio.h>

bool functionInput = false;

char GetInput() {
	char result = -4;

	while (result == -4) {
		if (_kbhit()) {
			result = _getch();
			
			functionInput = ( result == 0 || result == -32 );

			if (functionInput) result = _getch();
		};
	};

	return result;
}


bool PlayerAction()
{
	char currentKey;

	if (availableAction.size() <= 0) return true;

	currentKey = GetInput();

	if (currentKey) {
		for (Action* current : availableAction) {
			if (current->TryKey(currentKey)) {
				return true;
			};
		};
	};
	return false;
}