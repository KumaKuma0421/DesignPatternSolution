//
// Flywieght.h
//

#pragma once

#include <map>

namespace Primitive_Flyweight
{
    class Flyweight
    {
    public:
        Flyweight(int number) { _number = number; };
        virtual ~Flyweight() {};

    private:
        Flyweight() = delete;

        int _number;
    };

    class FlyweightFactory
    {
    public:
        FlyweightFactory() {};
        virtual ~FlyweightFactory() {};

        Flyweight* GetFlyweight(int number)
        {
            Flyweight* response = _container.at(number);
            if (nullptr == response)
            {
                response = new Flyweight(number);
                _container[number] = response;
            }

            return response;
        };

    private:
        std::map<int, Flyweight*> _container;
    };
}