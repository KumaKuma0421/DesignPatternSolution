//
// Shop.cpp
//

#include <iostream>
#include "Shop.h"

using namespace Sample;

VirtualShop* VirtualShop::_instance;

VirtualShop* VirtualShop::Instance ()
{
	if (!_instance) _instance = new VirtualShop ();
	return _instance;
}

void VirtualShop::Prepare ()
{
	_strategy[ICE_CREAM] = new IceCreamMaker ();
	_strategy[MENTOS] = new MentosMaker ();
	_strategy[COCA_COLA] = new CocaColaMaker ();
}

void VirtualShop::Stock (std::string item)
{
	Material* material = Factory (item);
	if (material) _stock[item] = material;
}

bool VirtualShop::Pickup (std::string item)
{
	bool ret = true;
	Material* response;
	Materials::iterator iterator;

	iterator = _stock.find (item);
	if (_stock.end () == iterator)
	{
		std::cout << "ストックされていません。探します。[" << item << "]" << std::endl;
		response = Factory (item);
		if (response) _stock[item] = response;
	}
	else
	{
		response = iterator->second;
	}

	if (response) _cart.push_back (response);
	else ret = false;

	return ret;
}

int VirtualShop::Check ()
{
	int price = 0;

	for (auto item : _cart)
	{
		std::cout << "お買い上げ:" << item->GetName ();
		std::cout << item->GetPrice ();
		std::cout << " 消費税 " << item->GetTax () << "%" << std::endl;
		price += item->GetTaxPrice ();
	}

	std::cout << "price is " << std::to_string (price) << std::endl;

	return price;
}

Material* VirtualShop::Factory (std::string item)
{
	Material* material;
	Strategies::iterator iterator;

	iterator = _strategy.find (item);
	if (_strategy.end () == iterator)
	{
		std::cout << "その商品は扱っていません。[" << item << "]" << std::endl;
		material = nullptr;
	}
	else
	{
		material = iterator->second->Make ();
	}

	return material;
}