//
// AbstractFactory.cpp
//

#include "AbstractFactory.h"
#include "BatchProcessFactory.h"
#include "RealtimeProcessFactory.h"

using namespace GoF_AbstractFactory;

StorageProduct::StorageProduct()
{

}

StorageProduct::~StorageProduct()
{

}

DisplayProduct::DisplayProduct()
{

}

DisplayProduct::~DisplayProduct()
{

}

ControlProduct::ControlProduct()
{

}

ControlProduct::~ControlProduct()
{

}

AbstractFactory::AbstractFactory()
{

}

AbstractFactory::~AbstractFactory()
{

}

AbstractFactory* AbstractFactory::CreateFactory(std::string type)
{
    AbstractFactory* response;

    if (type == "Batch")
    {
        response = new BatchProcessFactory();
    }
    else if (type == "Realtime")
    {
        response = new RealtimeProcessFactory();
    }
    else
    {
        response = nullptr;
    }

    return response;
}