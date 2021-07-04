//
// MemoryStorageProduct.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
    class MemoryStorageProduct : public StorageProduct
    {
    public:
        MemoryStorageProduct() {};
        ~MemoryStorageProduct() {};

        bool Store(std::string data);
        std::string Load();
    };
}