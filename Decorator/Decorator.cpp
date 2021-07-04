//
// TickCounter.cpp
//

#include "Decorator.h"

using namespace GoF_Decorator;

bool TickCounter::Action(DWORD dwParam)
{
    ULONGLONG start = GetTickCount64();
    bool ret = _core->Action(dwParam);
    ULONGLONG finish = GetTickCount64();

    ULONGLONG duration = finish - start;
    printf("duration = %lldms\n", duration);

    return ret;
}

FrequencyCounter::FrequencyCounter(Core* core)
{
    _core = core;
    QueryPerformanceFrequency(&_liFrequency);
}

bool FrequencyCounter::Action(DWORD dwParam)
{
    LARGE_INTEGER liStart;
    LARGE_INTEGER liFinish;

    QueryPerformanceCounter(&liStart);
    bool ret = _core->Action(dwParam);
    QueryPerformanceCounter(&liFinish);

    ULONGLONG ulDuration =
        (liFinish.QuadPart - liStart.QuadPart) * 1000 / _liFrequency.QuadPart;
    printf("duration = %lldms\n", ulDuration);

    return ret;
}

bool Execute::Action(DWORD dwParam)
{
    while (dwParam-- > 0)
    {
        printf(".");
        Sleep(1);
    }

    return true;
}