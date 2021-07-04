//
// FileStorageProduct.cpp
//

#include "FileStorageProduct.h"

using namespace GoF_AbstractFactory;

bool FileStorageProduct::Store(std::string data)
{
    return true;
}

std::string FileStorageProduct::Load()
{
    return "";
}