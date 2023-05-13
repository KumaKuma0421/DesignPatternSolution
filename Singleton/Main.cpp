//
// Main.cpp
//

#include <iostream>
#include <string>
#include "Singleton.h"

using namespace GoF_Singleton;

int main (int argc, char** argv)
{
	Singleton* instance1 = Singleton::getInstance ();
	Singleton* instance2 = Singleton::getInstance ();

	instance1->SetValue1 (1);
	instance1->SetValue2 (2);

	std::cout << "instance2->GetValue1():" <<
		std::to_string (instance2->GetValue1 ()) << std::endl;
	std::cout << "instance2->GetValue2():" <<
		std::to_string (instance2->GetValue2 ()) << std::endl;
}