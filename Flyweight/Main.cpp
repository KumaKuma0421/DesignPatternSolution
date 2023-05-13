//
// Main.cpp
//

#include <iostream>
#include "FlyweightFactory.h"

using namespace GoF_Flyweight;

int main (int argc, char** argv)
{
	FlyweightFactory factory;
	Flyweight* flyweight1 = factory.GetFlyweight ("Type1");
	Flyweight* flyweight2 = factory.GetFlyweight ("Type2");
	Flyweight* flyweight1a = factory.GetFlyweight ("Type1");
	Flyweight* flyweight2a = factory.GetFlyweight ("Type2");

	std::cout << "Done." << std::endl;
}