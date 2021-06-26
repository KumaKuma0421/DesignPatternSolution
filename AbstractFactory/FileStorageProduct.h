//
// FileStorageProduct.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
    class FileStorageProduct : public StorageProduct
    {
    public:
        FileStorageProduct();
        ~FileStorageProduct();

        bool Store(std::string data);
        std::string Load();
    };
}