//
// FlyweightFactory.h
//

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>

namespace GoF_Flyweight
{
    class Flyweight
    {
    public:
        Flyweight(std::string name) { _name = name; };
        virtual ~Flyweight() {};

        virtual std::string GetName() { return _name; };
        virtual std::string GetValue(std::string key) { return _map[key]; };

    private:
        friend class FlyweightFactory;
        virtual bool Initialize(std::string fileName);
        std::string _name;
        std::map<std::string, std::string> _map;
    };

    class FlyweightFactory
    {
    public:
        FlyweightFactory() {};
        virtual ~FlyweightFactory() {};

        Flyweight* GetFlyweight(std::string key);

    private:
        std::map<std::string, Flyweight*> _container;
    };
}