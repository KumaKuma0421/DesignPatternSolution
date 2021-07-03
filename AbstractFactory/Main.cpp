//
// Main.cpp
//

#include <iostream>
#include "AbstractFactory.h"

using namespace GoF_AbstractFactory;

int main(int argc, char** argv)
{
    AbstractFactory* factory1 = AbstractFactory::CreateFactory("Batch");

    StorageProduct* storage1 = factory1->CreateStorageProduct();
    DisplayProduct* display1 = factory1->CreateDisplayProduct();
    ControlProduct* control1 = factory1->CreateControlProduct();

    AbstractFactory* factory2 = AbstractFactory::CreateFactory("Realtime");

    StorageProduct* storage2 = factory1->CreateStorageProduct();
    DisplayProduct* display2 = factory1->CreateDisplayProduct();
    ControlProduct* control2 = factory1->CreateControlProduct();

    std::cout << "Done." << std::endl;
}