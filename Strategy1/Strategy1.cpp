//
// Strategy1.cpp
//

#include "Strategy1.h"

using namespace GoF_Strategy1;

int BeginStrategy::Action (void* param)
{
	std::cout << __FUNCTION__ << std::endl;
	return 0;
}

int NextStrategy::Action (void* param)
{
	std::cout << __FUNCTION__ << std::endl;
	return 0;
}

int PreviousStrategy::Action (void* param)
{
	std::cout << __FUNCTION__ << std::endl;
	return 0;
}

int EndStrategy::Action (void* param)
{
	std::cout << __FUNCTION__ << std::endl;
	return 0;
}

void Container::Add (std::string& criteria, Strategy1* strategy)
{
	_container[criteria] = strategy;
}

Strategy1* Container::Get (std::string& criteria)
{
	Strategy1* response;

	std::map<std::string, Strategy1*>::iterator it;
	it = _container.find (criteria);
	if (it == _container.end ())
	{
		response = nullptr;
	}
	else
	{
		response = it->second;
	}

	return response;
}
