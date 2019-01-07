#pragma once
#include "FSMState.h"
#include "Agent.h"
#include "Mining.h"

class Drinking : public FSMState
{

	void Enter(Agent* a) override;
	void Update(Agent* a) override;
	void Exit(Agent* a) override;

	bool once = false;

};
