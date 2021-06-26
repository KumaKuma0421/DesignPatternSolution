//
// BatchProcessFactory.cpp
//

#include "BatchProcessFactory.h"
#include "FileStorageProduct.h"
#include "ConsoleDisplayProduct.h"
#include "BatchControlProduct.h"

using namespace GoF_AbstractFactory;

BatchProcessFactory::BatchProcessFactory()
{

}

BatchProcessFactory::~BatchProcessFactory()
{

}

StorageProduct* BatchProcessFactory::CreateStorageProduct()
{
    return new FileStorageProduct();
}

DisplayProduct* BatchProcessFactory::CreateDisplayProduct()
{
    return new ConsoleDisplayProduct();
}

ControlProduct* BatchProcessFactory::CreateControlProduct()
{
    return new BatchControlProduct();
}
