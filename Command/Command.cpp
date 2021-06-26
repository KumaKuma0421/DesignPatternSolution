//
// Command.cpp
//

#include "Command.h"

using namespace GoF_Command;

TurnOnCommand::TurnOnCommand(Receiver* receiver)
    :Command(receiver)
{

}

bool TurnOnCommand::Execute()
{
    return _receiver->Action(1);
}

TurnOffCommand::TurnOffCommand(Receiver* receiver)
    :Command(receiver)
{

}

bool TurnOffCommand::Execute()
{
    return _receiver->Action(0);
}