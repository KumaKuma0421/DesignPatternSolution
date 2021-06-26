//
// BatchControlProduct.cpp
//

#include "BatchControlProduct.h"

using namespace GoF_AbstractFactory;

BatchControlProduct::BatchControlProduct()
{

}

BatchControlProduct::~BatchControlProduct()
{

}

bool BatchControlProduct::Start()
{
    return true;
}

bool BatchControlProduct::Stop()
{
    return true;
}