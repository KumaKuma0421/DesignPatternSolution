//
// Strategy1.h
//

#pragma once

#include <iostream>
#include <string>
#include <map>

namespace GoF_Strategy1
{
    class Strategy1
    {
    public:
        virtual int Action(void* param) = 0;
    };

    class BeginStrategy : public Strategy1
    {
    public:
        int Action(void* lpvParam);
    };

    class NextStrategy : public Strategy1
    {
    public:
        int Action(void* lpvParam);
    };

    class PreviousStrategy : public Strategy1
    {
    public:
        int Action(void* lpvParam);
    };

    class EndStrategy : public Strategy1
    {
    public:
        int Action(void* lpvParam);
    };

    class Container
    {
    public:
        void Add(std::string& criteria, Strategy1* strategy);
        Strategy1* Get(std::string& criteria);

    private:
        std::map<std::string, Strategy1*> _container;

    };
}