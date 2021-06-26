//
// Command.h
//

#pragma once

#include "Receiver.h"

namespace GoF_Command
{
    class Command
    {
    public:
        Command(Receiver* receiver) { _receiver = receiver; };
        virtual ~Command() {}

        virtual bool Execute() = 0;

    protected:
        Receiver* _receiver;
    };

    class TurnOnCommand : public Command
    {
    public:
        TurnOnCommand(Receiver* receiver);
        bool Execute();
    };

    class TurnOffCommand : public Command
    {
    public:
        TurnOffCommand(Receiver* receiver);
        bool Execute();
    };
}