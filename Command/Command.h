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
        Command(IReceiver* receiver) { _receiver = receiver; };
        virtual ~Command() {}

        virtual bool Execute() = 0;

    protected:
        IReceiver* _receiver;
    
    private:
        Command() = delete;
    };

    class TurnOnCommand : public Command
    {
    public:
        TurnOnCommand(IReceiver* receiver);
        ~TurnOnCommand() {};

        bool Execute();

    private:
        TurnOnCommand() = delete;
    };

    class TurnOffCommand : public Command
    {
    public:
        TurnOffCommand(IReceiver* receiver);
        ~TurnOffCommand() {};

        bool Execute();

    private:
        TurnOffCommand() = delete;
    };
}