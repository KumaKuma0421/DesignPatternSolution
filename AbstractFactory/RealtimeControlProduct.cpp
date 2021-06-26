//
// RealtimeControlProduct.cpp
//

#include "RealtimeControlProduct.h"

using namespace GoF_AbstractFactory;

RealtimeControlProduct::RealtimeControlProduct()
{

}

RealtimeControlProduct::~RealtimeControlProduct()
{

}

bool RealtimeControlProduct::Start()
{
    return true;
}

bool RealtimeControlProduct::Stop()
{
    return true;
}