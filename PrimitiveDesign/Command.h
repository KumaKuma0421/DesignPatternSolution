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
        Receiver() {};
        virtual ~Receiver() {};

        bool Action() { return true; };
    };

    class Command
    {
    public:
        Command(Receiver* receiver) { _receiver = receiver; };
        virtual ~Command() {};

        virtual bool Action() = 0;

    protected:
        Command() = delete;
        Receiver* _receiver;
    };

    class ConcreteCommand : public Command
    {
    public:
        ConcreteCommand(Receiver* receiver):Command(receiver) {};
        ~ConcreteCommand() {};

        bool Action() { return _receiver->Action(); };

    private:
        ConcreteCommand() = delete;
    };

    class Invoker
    {
    public:
        Invoker() {};
        virtual ~Invoker() {};

        void Add(Command* command) { _container.push_back(command); };
        bool Action()
        {
            bool ret = false;

            for (auto action : _container)
            {
                ret = action->Action();
                if (!ret) break;
            }

            return ret;
        };

    private:
        std::vector<Command*> _container;
    };
}