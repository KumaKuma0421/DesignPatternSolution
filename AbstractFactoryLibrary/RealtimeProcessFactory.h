//
// RealtimeProcessFactory.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC RealtimeProcessFactory : public AbstractFactory
	{
	public:
		RealtimeProcessFactory () {};
		~RealtimeProcessFactory () {};

		StorageProduct* CreateStorageProduct ();
		DisplayProduct* CreateDisplayProduct ();
		ControlProduct* CreateControlProduct ();
	};
}