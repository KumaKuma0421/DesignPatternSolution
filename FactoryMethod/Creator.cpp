//
// Creator.cpp
//

#include "Creator.h"

using namespace GoF_FactoryMethod;

Creator::Creator()
{

}

Creator::~Creator()
{

}

ConcreteCreator::ConcreteCreator()
{

}

ConcreteCreator::~ConcreteCreator()
{

}

Product* ConcreteCreator::CreateProduct()
{
    return new ConcreteProduct();
}