//
// RealtimeProcessFactory.cpp
//

#include "pch.h"
#include "RealtimeProcessFactory.h"
#include "MemoryStorageProduct.h"
#include "WindowDisplayProduct.h"
#include "RealtimeControlProduct.h"

using namespace GoF_AbstractFactory;

StorageProduct* RealtimeProcessFactory::CreateStorageProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new MemoryStorageProduct ();
}

DisplayProduct* RealtimeProcessFactory::CreateDisplayProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new WindowDisplayProduct ();
}

ControlProduct* RealtimeProcessFactory::CreateControlProduct ()
{
	FUNCTION_BEGIN ();
	FUNCTION_END ();
	return new RealtimeControlProduct ();
}