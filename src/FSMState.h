#pragma once
#include <stdlib.h>
#include "Colors.h"
class Agent;

class FSMState
{
public:
	virtual void Enter(Agent* a) = 0;
	virtual void Update(Agent* a) = 0;
	virtual void Exit(Agent* a) = 0;
};
