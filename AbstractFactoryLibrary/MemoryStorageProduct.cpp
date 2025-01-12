//
// MemoryStorageProduct.cpp
//

#include "pch.h"
#include "MemoryStorageProduct.h"

using namespace GoF_AbstractFactory;

bool MemoryStorageProduct::Store (std::string data)
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return true;
}

std::string MemoryStorageProduct::Load ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return "MemoryStorageProduct::Load";
}