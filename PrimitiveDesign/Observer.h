//
// Observer.h
//

#pragma once

#include <vector>

namespace Primitive_Observer
{
    class Observer
    {
    public:
        Observer() {};
        virtual ~Observer() {};

        virtual void Update() = 0;
    };

    class Subscriber
    {
    public:
        Subscriber() {};
        virtual ~Subscriber() {};

        virtual void Add(Observer* observer) { _observers.push_back(observer); };
        virtual void Notify()
        {
            for (auto observer : _observers)
            {
                observer->Update();
            }
        };

    private:
        std::vector<Observer*> _observers;
    };

    class ConcreteObserver1 : public Observer
    {
    public:
        ConcreteObserver1() {};
        ~ConcreteObserver1() {};
        
        void Update() {};
    };
    
    class ConcreteObserver2 : public Observer
    {
    public:
        ConcreteObserver2() {};
        ~ConcreteObserver2() {};

        void Update() {};
    };

    class ConcreteSubscriber : public Subscriber
    {
    public:
        ConcreteSubscriber() {};
        ~ConcreteSubscriber() {};
    };
}