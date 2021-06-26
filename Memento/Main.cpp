//
// Main.cpp
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "DataManager.h"

#define PREPARE_FILES 10

using namespace GoF_Memento;

bool prepare()
{
    for (int i = 1; i <= PREPARE_FILES; i++)
    {
        std::string temporary = "0000" + std::to_string(i);
        std::string fileName = temporary.substr(temporary.length() - 4) + ".txt";
        std::ofstream ofs(fileName);
        if (!ofs) return false;
        std::string data;
        for (int j = 0; j < 10; j++)
        {
            data = "This is a test string No." + std::to_string(j) + "\n";
            ofs << data;
        }
        ofs.close();
    }

    return true;
}

int main(int argc, char** argv)
{
    bool ret = prepare();

    DataManager manager;
    std::string data;
    int hitCount = 0;
    int missCount = 0;

    std::srand((unsigned int)time(nullptr));

    for (int i = 1; i <= 100; i++)
    {
        int index = std::rand() % PREPARE_FILES + 1;
        std::cout << "index = " << index << std::endl;

        bool ret = manager.Get(index, data);
        if (ret) hitCount++;
        else missCount++;

        double ratio = (double)hitCount / (double)(hitCount + missCount);
        if (ret) std::cout << "hit ratio=" << std::to_string(ratio) << std::endl;
        //std::cout << data << std::endl;
    }

    std::cout << "Done." << std::endl;
}