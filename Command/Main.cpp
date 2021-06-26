//
// Main.cpp
//

#include <iostream>
#include "Command.h"
#include "Receiver.h"
#include "Invoker.h"

using namespace GoF_Command;

int main(int argc, char** argv)
{
    Invoker invoker;
    RealReceiver receiver;
    TurnOnCommand turnOn(&receiver);
    TurnOffCommand turnOff(&receiver);

    invoker.Add(&turnOff);
    invoker.Add(&turnOn);
    invoker.Add(&turnOff);
    invoker.Add(&turnOn);

    invoker.Execute();

    std::cout << "Done." << std::endl;
}
