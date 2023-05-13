//
// Invoker.h
//

#pragma once

#include <vector>
#include "Command.h"

namespace GoF_Command
{
	class Invoker
	{
	public:
		Invoker () {};
		virtual ~Invoker () {};

		void Add (Command* command) { _commands.push_back (command); };
		bool Execute ();

	private:
		std::vector<Command*> _commands;
	};
}