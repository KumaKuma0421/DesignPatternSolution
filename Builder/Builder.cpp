//
// Builder.cpp
//

#include "Builder.h"

using namespace GoF_Builder;

Product::Product (std::string name)
{
	_name = name;
}

MetalProduct::MetalProduct (std::string name)
	:Product(name)
{
}

std::string MetalProduct::GetName ()
{
	return "This is " + _name + ".";
}

std::string MetalProduct::GetSpec ()
{
	return "This " + _name + " is so hard.";
}

WoodProduct::WoodProduct (std::string name)
	:Product(name)
{
}

std::string WoodProduct::GetName ()
{
	return "This is " +_name + ".";
}

std::string WoodProduct::GetSpec ()
{
	return "This " + _name + " is so soft.";
}

Product* MetalBuilder::BuildProduct ()
{
	return new MetalProduct ("iron");
}

Product* WoodBuilder::BuildProduct ()
{
	return new WoodProduct ("rawang");
}