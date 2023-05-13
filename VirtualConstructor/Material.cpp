//
// Material.cpp
//

#include "Material.h"

using namespace Sample;

Material::Material (std::string id, std::string name, int price, int tax)
{
	_id = id;
	_name = name;
	_price = price;
	_tax = tax;
}