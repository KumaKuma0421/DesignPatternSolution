//
// MemoryStorageProduct.cpp
//

#include "MemoryStorageProduct.h"

using namespace GoF_AbstractFactory;

MemoryStorageProduct::MemoryStorageProduct()
{

}

MemoryStorageProduct::~MemoryStorageProduct()
{

}

bool MemoryStorageProduct::Store(std::string data)
{
    return true;
}

std::string MemoryStorageProduct::Load()
{
    return "";
}