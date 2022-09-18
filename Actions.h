#ifndef __ACTION
#define __ACTION

#include <vector>

extern std::vector<class Action*> availableAction;
extern class Action action_Attack;
extern class Action action_Skill;
extern class Action action_Defence;
extern class Action action_Fill_Health;

class Action
{
	char key;
	const char* explain;
	bool (*currentFunction)();
		
public:
	Action( char wantKey, const char* wantExplain, bool(*wantFunction)() ) {
		key = wantKey;
		explain = wantExplain;
		currentFunction = wantFunction;
	}

	__inline char			GetKey()	 { return key; }
	__inline char			GetUpperKey(){ return (key >= 'a' && key <= 'z') ? key - 32 : key ; }
	__inline char			GetLowerKey(){ return (key >= 'A' && key <= 'Z') ? key + 32 : key; }
	__inline const char*	GetExplain() { return explain; }

	bool TryKey(char wantKey)
	{
		if (key != wantKey) return false;
		if (currentFunction == nullptr) return false;

		return currentFunction();
	}
};

void ClearAction();
void AddAction(Action& target);
void ImportCombatAction(); 



#endif
