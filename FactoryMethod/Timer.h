//
// Timer.h
//

#pragma once

#include <vector>
#include "Watcher.h"

namespace GoF_FactoryMethod
{
    class Subscriber
    {
    public:
        void Notify();
        void AddObserver(Observer* observer);

    private:
        std::vector<Observer*> _observers;
    };

    class Timer : public Subscriber
    {
    public:
        Timer();
        virtual ~Timer();

        void Notify();
    };
}