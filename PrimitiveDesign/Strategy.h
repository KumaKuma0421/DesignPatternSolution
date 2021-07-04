//
// Strategy.h
//

#pragma once

#include <map>

namespace Primitive_Strategy
{
    class IStrategy
    {
    public:
        virtual ~IStrategy() {};
        virtual void Action() = 0;
    };

    class Strategy1 : public IStrategy
    {
    public:
        Strategy1() {};
        ~Strategy1() {};

        void Action() {};
    };

    class Strategy2 : public IStrategy
    {
    public:
        Strategy2() {};
        ~Strategy2() {};

        void Action() {};
    };

    class Strategy3 : public IStrategy
    {
    public:
        Strategy3() {};
        ~Strategy3() {};

        void Action() {};
    };

    class Invoker
    {
    public:
        Invoker()
        {
            _container[0] = new Strategy1();
            _container[1] = new Strategy2();
            _container[2] = new Strategy3();
        };
        virtual ~Invoker() {};

        virtual void Action(int action)
        {
            IStrategy* strategy = _container.at(action);
            if (strategy) strategy->Action();
        };

    private:
        std::map<int, IStrategy*> _container;
    };
}