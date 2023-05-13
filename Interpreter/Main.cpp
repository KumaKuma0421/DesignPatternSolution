//
// Main.cpp
//

#include <iostream>
#include "Interpreter.h"

using namespace GoF_Interpreter;

int main (int argc, char** argv)
{
	Interpreter interpreter;

	interpreter.Load ("CommandList.txt");

	interpreter.Interpret ();

	interpreter.Run ();

	std::cout << "Done." << std::endl;
}