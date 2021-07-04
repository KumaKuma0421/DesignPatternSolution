//
// Main.cpp
//

#include <stdio.h>
#include "AbstractBridge.h"

using namespace GoF_Bridge;

void WindowsTest()
{
    WindowsFileOperation test;
    test.InitInstance();
    test.ReadRowTest();
    test.ExitInstance();
}

void UnixTest()
{
    UnixFileOperation test;
    test.InitInstance();
    test.ReadRowTest();
    test.ExitInstance();
}

int main(int argc, char** argv)
{
    WindowsTest();
    UnixTest();

    printf("Done.");

    return 0;
}
