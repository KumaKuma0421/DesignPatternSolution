//
// BatchControlProduct.cpp
//

#include "pch.h"
#include "BatchControlProduct.h"

using namespace GoF_AbstractFactory;

bool BatchControlProduct::Start ()
{
	FUNCTION_BEGIN();

	std::cout << "Start." << std::endl;

	FUNCTION_END ();
	return true;
}

bool BatchControlProduct::Stop ()
{
	FUNCTION_BEGIN ();

	std::cout << "Stop." << std::endl;

	FUNCTION_END ();
	return true;
}