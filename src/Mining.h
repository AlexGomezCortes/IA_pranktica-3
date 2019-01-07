#pragma once
#include "FSMState.h"
#include "BankDeposit.h"
#include "Drinking.h"
#include "Agent.h"



class Mining : public FSMState
{

	void Enter(Agent* a) override;
    void Update(Agent* a) override;
	void Exit(Agent* a) override;

	bool once=false;

};
