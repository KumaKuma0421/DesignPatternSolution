//
// Main.cpp
//

#include <iostream>
#include "Observer.h"
#include "Subscriber.h"

using namespace GoF_Observer;

int main (int argc, char** argv)
{
	ClockGenerator clock;
	Watcher watcher1 (1);
	Watcher watcher2 (2);
	Watcher watcher3 (3);

	std::cout << "Nothing." << std::endl;
	clock.Clock ();

	std::cout << "Add watcher1." << std::endl;
	clock.Add (&watcher1);
	clock.Clock ();

	std::cout << "Add watcher2." << std::endl;
	clock.Add (&watcher2);
	clock.Clock ();

	std::cout << "Add watcher3." << std::endl;
	clock.Add (&watcher3);
	clock.Clock ();

	std::cout << "Remove watcher3." << std::endl;
	clock.Remove (&watcher3);
	clock.Clock ();

	std::cout << "Remove watcher2." << std::endl;
	clock.Remove (&watcher2);
	clock.Clock ();

	std::cout << "Remove watcher1." << std::endl;
	clock.Remove (&watcher1);
	clock.Clock ();

	std::cout << "Nothing." << std::endl;
	clock.Clock ();

	std::cout << "Done." << std::endl;
}
