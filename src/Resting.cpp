#include "Resting.h"

void Resting::Enter(Agent* a)
{
	a->restQuantity = 0.0f;
	a->pocketsFull = false;
	a->totalGold = 0.0f;
	a->goldAmount = 0.0f;
}

void Resting::Update(Agent * a)
{
	a->restQuantity += 0.02;

	if (!once)
	{
		std::cout << green << "Resting..." << std::endl;
		once = true;
	}

	if (a->restQuantity >= 8.0f)
	{
		a->rested = true;
		a->needToMine = true;
		Exit(a);
	}
}

void Resting::Exit(Agent * a)
{
	if (a->rested && a->needToMine)
	{
		a->state = new Mining();
		a->state->Enter(a);
	}
}
