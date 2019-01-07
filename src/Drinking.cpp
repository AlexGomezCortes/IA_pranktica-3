#include "Drinking.h"

void Drinking::Enter(Agent * a)
{
	a->thirstyQuantity = 0.0f;
}

void Drinking::Update(Agent * a)
{
	a->thirstyQuantity += 0.02f;
	//system("cls");

	if (!once)
	{
		std::cout << blue << "Drinking..." << std::endl;
		once = true;
	}
	

	if (a->thirstyQuantity >= 9.0f)
	{
		a->thirsty = false;		
		a->thirstyQuantity = 0.0f;
		a->rested = false;
		a->needToMine = true;
		a->rich = false;
		Exit(a);
		
	}

}

void Drinking::Exit(Agent * a)
{
	if (a->needToMine)
	{
		a->state = new Mining();
		a->state->Enter(a);
	}
		
}
