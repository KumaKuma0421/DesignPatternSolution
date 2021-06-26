//
// ConsoleDisplayProduct.cpp
//

#include "ConsoleDisplayProduct.h"

using namespace GoF_AbstractFactory;

ConsoleDisplayProduct::ConsoleDisplayProduct()
{

}

ConsoleDisplayProduct::~ConsoleDisplayProduct()
{

}

bool ConsoleDisplayProduct::Show(std::string message)
{
    return true;
}