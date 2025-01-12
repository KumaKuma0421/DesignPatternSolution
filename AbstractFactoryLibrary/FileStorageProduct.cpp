//
// FileStorageProduct.cpp
//

#include "pch.h"
#include "FileStorageProduct.h"

using namespace GoF_AbstractFactory;

bool FileStorageProduct::Store (std::string data)
{
	FUNCTION_BEGIN ();
	std::cout << data << std::endl;
	FUNCTION_END ();
	return true;
}

std::string FileStorageProduct::Load ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return "FileStorageProduct::Load";
}