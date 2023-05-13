//
// Strategy2.cpp
//

#include "Strategy2.h"

using namespace GoF_Strategy2;

int Strategy2::Init ()
{
	Function begin = [&](void* param)->int
	{
		printf ("Begin");
		return 0;
	};
	_container["Begin"] = begin;

	Function next = [&](void* param)->int
	{
		printf ("Next");
		return 0;
	};
	_container["Next"] = next;

	Function previous = [&](void* param)->int
	{
		printf ("Previous");
		return 0;
	};
	_container["Previous"] = previous;

	Function end = [&](void* param)->int
	{
		printf ("End");
		return 0;
	};
	_container["End"] = end;

	return 0;
}

int Strategy2::Action (std::string criteria)
{
	int ret = -1;

	std::map<std::string, Function>::iterator it;
	it = _container.find (criteria);
	if (it != _container.end ())
	{
		Function function = it->second;
		ret = function (this);
	}

	return ret;
}