//
// Receiver.h
//

#pragma once

#include <iostream>

namespace GoF_Command
{
    class Receiver
    {
    public:
        virtual bool Action(int param) = 0;
    };

    class RealReceiver : public Receiver
    {
    public:
        bool Action(int param);
    };
}