//
// Creator.cpp
//

#include "Creator.h"

using namespace GoF_FactoryMethod;

Product* ConcreteCreator::CreateProduct()
{
    return new ConcreteProduct();
}