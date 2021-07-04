//
// MemoryStorageProduct.cpp
//

#include "MemoryStorageProduct.h"

using namespace GoF_AbstractFactory;

bool MemoryStorageProduct::Store(std::string data)
{
    return true;
}

std::string MemoryStorageProduct::Load()
{
    return "";
}