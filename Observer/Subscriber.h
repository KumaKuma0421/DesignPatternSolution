//
// Subscriber.h
//

#pragma once

#include <iostream>
#include <vector>
#include "Observer.h"

namespace GoF_Observer
{
    class Subscriber
    {
    public:
        Subscriber() {};
        virtual ~Subscriber() {};

        virtual void Add(Observer* observer)
        {
            _observers.push_back(observer);
        };

        virtual void Remove(Observer* observer)
        {
            for (auto iterator = _observers.begin(); iterator != _observers.end(); iterator++)
            {
                if (*iterator == observer)
                {
                    _observers.erase(iterator);
                    break;
                }
            }
        };

        virtual void Notify(int count)
        {
            for (auto observer : _observers)
            {
                observer->Update(count);
            }
        };

    protected:
        std::vector<Observer*> _observers;
    };

    class ClockGenerator : public Subscriber
    {
    public:
        ClockGenerator() { _count = 0; };
        ~ClockGenerator() {};

        void Clock()
        {
            std::cout << "Clock " << std::to_string(_count) << std::endl;
            Notify(_count++);
        };

    private:
        int _count;
    };
}