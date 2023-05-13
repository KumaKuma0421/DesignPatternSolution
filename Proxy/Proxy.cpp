//
// Proxy.cpp
//

#include "Proxy.h"

using namespace GoF_Proxy;

bool Proxy::Action1 (int param)
{
	std::cout << "Proxy::Action1()" << std::endl;

	return true;
}

bool Proxy::Action2 (int param)
{
	std::cout << "Proxy::Action2()" << std::endl;

	if (_core == nullptr) _core = new SpecialCore ();

	return _core->Action2 (param);
}

bool SpecialCore::Action1 (int param)
{
	std::cout << "SpecialCore::Action1()" << std::endl;

	return true;
}

bool SpecialCore::Action2 (int param)
{
	std::cout << "SpecialCore::Action2()" << std::endl;

	return true;
}