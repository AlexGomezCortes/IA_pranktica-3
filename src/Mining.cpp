#include "Mining.h"

void Mining::Enter(Agent * a)
{
	a->goldAmount = 0.0f;
}

void Mining::Update(Agent * a)
{
	a->goldAmount += 0.02f;
	a->thirstyQuantity += 0.02f;
	//system("cls");

	if (!once)
	{
		std::cout << yellow << "Digging..." << std::endl;
		once = true;
	}
	

	if (a->goldAmount >= 10.0f)
	{		
		a->pocketsFull = true;
		a->rich = false;
		a->thirsty = false;
		a->rested = false;
		a->needToMine = false;
		once = false;
		Exit(a);
	}
	if (a->thirstyQuantity > 19.0f)
	{
		a->pocketsFull = false;
		a->rich = false;
		a->thirsty = true;
		a->rested = false;
		once = false;
		Exit(a);
	}

}

void Mining::Exit(Agent * a)
{
	if (a->pocketsFull)
	{
		a->state = new BankDeposit();
		a->state->Enter(a);
		return;
	}
		

	if (a->thirsty)
	{
		a->state = new Drinking();
		a->state->Enter(a);
		return;
	}
		
}
