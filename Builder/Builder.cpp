//
// Builder.cpp
//

#include "Builder.h"

using namespace GoF_Builder;

void Maker::SelectBuilder (std::string builder)
{
	if (builder == "Concrete")
	{
		_selectedBuilder = new ConcreteBuilder ();
	}
	else if (builder == "Wood")
	{
		_selectedBuilder = new WoodBuilder ();
	}
	else
	{
		_selectedBuilder = nullptr;
	}
}

std::string Maker::GetPrint ()
{
	return _selectedBuilder->Build ();
}

std::string ConcreteBuilder::Build ()
{
	std::string buildmemo;

	buildmemo = "これはコンクリート製の";
	buildmemo += "家屋の作り方の設計図です。";

	return buildmemo;
}

std::string WoodBuilder::Build ()
{
	std::string buildmemo;

	buildmemo = "これは木造の";
	buildmemo += "家屋の作り方の設計図です。";

	return buildmemo;
}