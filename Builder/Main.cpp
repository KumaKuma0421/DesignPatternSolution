//
// Main.cpp
//

#include <iostream>
#include "Builder.h"

using namespace GoF_Builder;

int main (int argc, char** argv)
{
	Maker maker1;
	maker1.SelectBuilder ("Concrete");
	std::string paper1 = maker1.GetPrint ();
	std::cout << paper1 << std::endl;

	Maker maker2;
	maker2.SelectBuilder ("Wood");
	std::string paper2 = maker2.GetPrint ();
	std::cout << paper2 << std::endl;

	std::cout << "Done." << std::endl;
}