//
// Timer.cpp
//

#include "Timer.h"

using namespace GoF_FactoryMethod;

void Subscriber::Notify()
{
    for (auto item : _observers)
    {
        item->Update();
    }
}

void Subscriber::AddObserver(Observer* observer)
{
    _observers.push_back(observer);
}

Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::Notify()
{

}