//
// Invoker.cpp
//

#include "Invoker.h"

using namespace GoF_Command;

bool Invoker::Execute ()
{
	bool ret = false;

	for (Command* command : _commands)
	{
		ret = command->Execute ();
		if (!ret) break;
	}

	return ret;
}