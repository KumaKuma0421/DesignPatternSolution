//
// BatchProcessFactory.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
    class BatchProcessFactory : public AbstractFactory
    {
    public:
        BatchProcessFactory();
        ~BatchProcessFactory();

        StorageProduct* CreateStorageProduct();
        DisplayProduct* CreateDisplayProduct();
        ControlProduct* CreateControlProduct();
    };
}
