//
// Main.cpp
//

#include <iostream>
#include "Decorator.h"

using namespace GoF_Decorator;

int main (int argc, char** argv)
{
	const DWORD cdwCount = 100;

	Execute execute;
	execute.Action (cdwCount);

	TickCounter TCounter (&execute);
	TCounter.Action (cdwCount);

	FrequencyCounter FCounter (&execute);
	FCounter.Action (cdwCount);

	std::cout << "Done." << std::endl;
}