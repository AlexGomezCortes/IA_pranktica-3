#include "BankDeposit.h"

void BankDeposit::Enter(Agent * a)
{
	a->totalGold += a->goldAmount;
	a->goldAmount = 0.0f;
}

void BankDeposit::Update(Agent * a)
{
	//system("cls");
	std::cout << red << "Depositing..." << std::endl;
	

	if (a->totalGold >= 20.0f)
	{
		a->rich = true;
		a->thirsty = false;
		a->rested = false;
		a->needToMine = false;

		Exit(a);
	}
	else
	{
		a->rich = false;
		a->thirsty = false;
		a->rested = false;
		a->needToMine = true;
		Exit(a);
	}
}

void BankDeposit::Exit(Agent * a)
{
	if (a->rich)
	{
		a->state = new Resting();
		a->state->Enter(a);
		return;
	}
	if (a->needToMine)
	{
		a->state = new Mining();
		a->state->Enter(a); 
		return;
	}
}
