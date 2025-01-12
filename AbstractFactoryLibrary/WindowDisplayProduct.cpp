//
// WindowDisplayProduct.cpp
//

#include "pch.h"
#include "WindowDisplayProduct.h"

using namespace GoF_AbstractFactory;

bool WindowDisplayProduct::Show (std::string message)
{
	FUNCTION_BEGIN ();
	std::cout << message << std::endl;
	FUNCTION_END ();
	return true;
}