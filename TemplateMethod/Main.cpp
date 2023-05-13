//
// Main.cpp
//

#include <iostream>
#include "TemplateMethod.h"

using namespace GoF_TempateMethod;

int main (int argc, char** argv)
{
	TemplateAction action;

	action.Action ();

	std::cout << "Done." << std::endl;
}