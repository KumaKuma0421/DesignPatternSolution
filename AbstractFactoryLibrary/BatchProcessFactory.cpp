//
// BatchProcessFactory.cpp
//

#include "pch.h"
#include "BatchProcessFactory.h"
#include "FileStorageProduct.h"
#include "ConsoleDisplayProduct.h"
#include "BatchControlProduct.h"

using namespace GoF_AbstractFactory;

StorageProduct* BatchProcessFactory::CreateStorageProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new FileStorageProduct ();
}

DisplayProduct* BatchProcessFactory::CreateDisplayProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new ConsoleDisplayProduct ();
}

ControlProduct* BatchProcessFactory::CreateControlProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new BatchControlProduct ();
}
