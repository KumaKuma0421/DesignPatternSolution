//
// Strategy.h
//

#pragma once

#include <map>

namespace Primitive_Strategy
{
    class Strategy
    {
    public:
        Strategy() {};
        virtual ~Strategy() {};

        virtual void Action() = 0;
    };

    class ConcreteStrategy1 : public Strategy
    {
    public:
        ConcreteStrategy1() {};
        ~ConcreteStrategy1() {};

        void Action() {};
    };

    class ConcreteStrategy2 : public Strategy
    {
    public:
        ConcreteStrategy2() {};
        ~ConcreteStrategy2() {};

        void Action() {};
    };

    class ConcreteStrategy3 : public Strategy
    {
    public:
        ConcreteStrategy3() {};
        ~ConcreteStrategy3() {};

        void Action() {};
    };

    class Invoker
    {
    public:
        Invoker()
        {
            _container[0] = new ConcreteStrategy1();
            _container[1] = new ConcreteStrategy2();
            _container[2] = new ConcreteStrategy3();
        };
        virtual ~Invoker() {};

        virtual void Action(int action)
        {
            Strategy* strategy = _container.at(action);
            if (strategy) strategy->Action();
        };

    private:
        std::map<int, Strategy*> _container;
    };
}