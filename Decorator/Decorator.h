//
// TickCounter.h
//

#pragma once

#include <Windows.h>
#include <stdio.h>

namespace GoF_Decorator
{
    class Core
    {
    public:
        virtual bool Action(DWORD dwParam) = 0;
    };

    class TickCounter : public Core
    {
    public:
        TickCounter(Core* core);

        bool Action(DWORD dwParam);

    private:
        Core* _core;
    };

    class FrequencyCounter : public Core
    {
    public:
        FrequencyCounter(Core* core);

        bool Action(DWORD dwParam);

    private:
        Core* _core;
        LARGE_INTEGER _liFrequency;
    };

    class Execute : public Core
    {
    public:
        bool Action(DWORD dwParam);
    };
}