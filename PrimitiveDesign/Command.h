//
// Command.h
//

#pragma once

#include <vector>

namespace Primitive_Command
{
	class Receiver
	{
	public:
		Receiver () {};
		virtual ~Receiver () {};

		bool Action (int number) { return true; };
	};

	class AbstractCommand
	{
	public:
		AbstractCommand (Receiver* receiver) { _receiver = receiver; };
		virtual ~AbstractCommand () {};

		virtual bool Action () = 0;

	protected:
		AbstractCommand () = delete;
		Receiver* _receiver;
	};

	class Command1 : public AbstractCommand
	{
	public:
		Command1 (Receiver* receiver) :AbstractCommand (receiver) {};
		~Command1 () {};

		bool Action () { return _receiver->Action (1); };

	private:
		Command1 () = delete;
	};

	class Command2 : public AbstractCommand
	{
	public:
		Command2 (Receiver* receiver) :AbstractCommand (receiver) {};
		~Command2 () {};

		bool Action () { return _receiver->Action (2); };

	private:
		Command2 () = delete;
	};

	class Invoker
	{
	public:
		Invoker () {};
		virtual ~Invoker () {};

		void Add (AbstractCommand* command) { _container.push_back (command); };
		bool Action ()
		{
			bool ret = false;

			for (auto action : _container)
			{
				ret = action->Action ();
				if (!ret) break;
			}

			return ret;
		};

	private:
		std::vector<AbstractCommand*> _container;
	};
}