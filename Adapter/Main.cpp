//
// Main.cpp
//

#include <iostream>
#include "Adapter.h"

using namespace GoF_Adapter;

int main(int argc, char** argv)
{
    Adapter adapter;
    char string[80];

    adapter.Init();

    adapter.SetProfileString("Section1", "Keyword1", "Sample1");
    adapter.SetProfileString("Section1", "Keyword2", "Sample2");
    adapter.SetProfileString("Section2", "Keyword1", "Test1");
    adapter.SetProfileString("Section2", "Keyword2", "Test2");

    adapter.GetProfileString("Section1", "Keyword1", string, 80);
    std::cout << string << std::endl;
    adapter.GetProfileString("Section1", "Keyword2", string, 80);
    std::cout << string << std::endl;
    adapter.GetProfileString("Section2", "Keyword1", string, 80);
    std::cout << string << std::endl;
    adapter.GetProfileString("Section2", "Keyword2", string, 80);
    std::cout << string << std::endl;

    adapter.Exit();
}