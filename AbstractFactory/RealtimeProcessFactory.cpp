//
// RealtimeProcessFactory.cpp
//

#include "RealtimeProcessFactory.h"
#include "MemoryStorageProduct.h"
#include "WindowDisplayProduct.h"
#include "RealtimeControlProduct.h"

using namespace GoF_AbstractFactory;

RealtimeProcessFactory::RealtimeProcessFactory()
{

}

RealtimeProcessFactory::~RealtimeProcessFactory()
{

}

StorageProduct* RealtimeProcessFactory::CreateStorageProduct()
{
    return new MemoryStorageProduct();
}

DisplayProduct* RealtimeProcessFactory::CreateDisplayProduct()
{
    return new WindowDisplayProduct();
}

ControlProduct* RealtimeProcessFactory::CreateControlProduct()
{
    return new RealtimeControlProduct();
}