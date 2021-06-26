//
// Main.cpp
//

#include <iostream>
#include "Proxy.h"

using namespace GoF_Proxy;

int main(int argc, char** argv)
{
    Proxy proxy;

    proxy.Action1(1);
    proxy.Action2(2);

    std::cout << "Done." << std::endl;
}
