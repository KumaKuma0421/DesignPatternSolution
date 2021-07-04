//
// Command.cpp
//

#include "Command.h"

using namespace GoF_Command;

TurnOnCommand::TurnOnCommand(IReceiver* receiver)
    :Command(receiver)
{

}

bool TurnOnCommand::Execute()
{
    return _receiver->Action(1);
}

TurnOffCommand::TurnOffCommand(IReceiver* receiver)
    :Command(receiver)
{

}

bool TurnOffCommand::Execute()
{
    return _receiver->Action(0);
}