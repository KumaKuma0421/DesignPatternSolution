//
// Observer.h
//

#pragma once

#include <iostream>
#include <string>

namespace GoF_Observer
{
	class Observer
	{
	public:
		Observer () {};
		virtual ~Observer () {};

		virtual void Update (int count) = 0;
	};

	class Watcher : public Observer
	{
	public:
		Watcher (int id) { _id = id; };
		~Watcher () {};

		void Update (int count)
		{
			std::cout << "Watcher " << std::to_string (_id);
			std::cout << " Get update " << std::to_string (count) << std::endl;
		};

	private:
		Watcher () = delete;

		int _id;
	};
}