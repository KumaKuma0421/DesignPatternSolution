//
// WindowDisplayProduct.cpp
//

#include "WindowDisplayProduct.h"

using namespace GoF_AbstractFactory;

WindowDisplayProduct::WindowDisplayProduct()
{

}

WindowDisplayProduct::~WindowDisplayProduct()
{

}

bool WindowDisplayProduct::Show(std::string message)
{
    return true;
}