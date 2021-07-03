//
// Observer.h
//

#pragma once

#include <vector>

namespace Primitive_Observer
{
    class IObserver
    {
    public:
        virtual void Update() = 0;
    };

    class Subscriber
    {
    public:
        Subscriber() {};
        virtual ~Subscriber() {};

        virtual void Add(IObserver* observer) { _observers.push_back(observer); };
        virtual void Notify()
        {
            for (auto observer : _observers)
            {
                observer->Update();
            }
        };

    private:
        std::vector<IObserver*> _observers;
    };

    class Observer1 : public IObserver
    {
    public:
        Observer1() {};
        ~Observer1() {};

        void Update() {};
    };

    class Observer2 : public IObserver
    {
    public:
        Observer2() {};
        ~Observer2() {};

        void Update() {};
    };

    class ConcreteSubscriber : public Subscriber
    {
    public:
        ConcreteSubscriber() {};
        ~ConcreteSubscriber() {};
    };
}