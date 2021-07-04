//
// Strategy2.h
//

#pragma once

#include <functional>
#include <string>
#include <map>
#include <stdio.h>

namespace GoF_Strategy2
{
    typedef std::function<int(void*)> Function;

    class Strategy2
    {
    public:
        Strategy2() {};
        virtual ~Strategy2() {};

        int Init();
        int Action(std::string criteria);

    private:
        std::map<std::string, Function> _container;
    };
}