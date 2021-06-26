//
// Proxy.h
//

#pragma once

#include <iostream>

namespace GoF_Proxy
{
    class Core
    {
    public:
        Core() {};
        virtual ~Core() {};

        virtual bool Action1(int param) = 0;
        virtual bool Action2(int param) = 0;
    };

    class Proxy : public Core
    {
    public:
        Proxy() { _core = nullptr; };
        ~Proxy() {};

        bool Action1(int param);
        bool Action2(int param);

    private:
        Core* _core;
    };

    class SpecialCore : public Core
    {
    public:
        SpecialCore() {};
        ~SpecialCore() {};

        bool Action1(int param);
        bool Action2(int param);
    };
}