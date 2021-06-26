//
// Main.cpp
//

#include <iostream>
#include "Creator.h"
#include "Product.h"

using namespace GoF_FactoryMethod;

int main(int argc, char** argv)
{
    ConcreteCreator creator;
    Product* product = creator.CreateProduct();

    std::cout << "Done." << std::endl;
}