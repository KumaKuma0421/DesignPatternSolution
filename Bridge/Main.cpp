//
// Main.cpp
//

#include <stdio.h>
#include "AbstractBridge.h"

using namespace GoF_Bridge;

int main(int argc, char** argv)
{
    UnixFileOperation test1;

    test1.InitInstance();
    test1.ReadRowTest();
    test1.ExitInstance();

    printf("Done.");

    return 0;
}
