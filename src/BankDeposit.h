#pragma once
#include "FSMState.h"
#include "Resting.h"
#include "Agent.h"


class BankDeposit : public FSMState
{

	void Enter(Agent* a) override;
	void Update(Agent* a) override;
	void Exit(Agent* a) override;

};
