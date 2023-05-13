//
// Main.cpp
//

#include <iostream>
#include "Validation.h"
#include "assert.h"

using namespace GoF_ChainOfResponsibility;

bool IntegerCheck (int value)
{
	Validation<int> Check;
	PositiveValidation<int> PositiveCheck;
	MinValidation<int> MinCheck (3);
	MaxValidation<int> MaxCheck (10);
	RangeValidation<int> RangeCheck (5, 8);

	Check
		.SetNext (PositiveCheck)
		.SetNext (MinCheck)
		.SetNext (MaxCheck)
		.SetNext (RangeCheck);

	bool ret = Check.Request (value);
	std::cout << Check.GetReason () << std::endl;

	return ret;
}

bool doubleCheck (double value)
{
	Validation<double> Check;
	PositiveValidation<double> PositiveCheck;
	MinValidation<double> MinCheck (3.2);
	MaxValidation<double> MaxCheck (10.6);
	RangeValidation<double> RangeCheck (4.8, 7.8);

	Check
		.SetNext (PositiveCheck)
		.SetNext (MinCheck)
		.SetNext (MaxCheck)
		.SetNext (RangeCheck);

	bool ret = Check.Request (value);
	std::cout << Check.GetReason () << std::endl;

	return ret;
}

int main (int argc, char** argv)
{
	std::cout << "Start." << std::endl;

	std::cout << "IntegerCheck(7)" << std::endl;
	assert (IntegerCheck (7));

	std::cout << "IntegerCheck(4)" << std::endl;
	assert (!IntegerCheck (4));

	std::cout << "IntegerCheck(-5)" << std::endl;
	assert (!IntegerCheck (-5));

	std::cout << "doubleCheck(6.6)" << std::endl;
	assert (doubleCheck (6.6));

	std::cout << "doubleCheck(8.3)" << std::endl;
	assert (!doubleCheck (8.3));

	std::cout << "Done." << std::endl;
}
