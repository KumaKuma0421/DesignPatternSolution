//
// Main.cpp
//

#include <iostream>
#include "Strategy2.h"

using namespace GoF_Strategy2;

int main(int argc, char** argv)
{
    Strategy2 strategy;

    strategy.Init();

    int ret = strategy.Action("Begin");

    return ret;
}
