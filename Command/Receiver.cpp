//
// Receiver.cpp
//

#include "Receiver.h"

using namespace GoF_Command;

bool RealReceiver::Action(int param)
{
    bool ret = true;

    switch (param)
    {
    case 0:
        std::cout << "Trun OFF." << std::endl;
        break;

    case 1:
        std::cout << "Turn ON." << std::endl;
        break;

    default:
        std::cout << "Invalid command." << std::endl;
        ret = false;
        break;
    }

    return ret;
}