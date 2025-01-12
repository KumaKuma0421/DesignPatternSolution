//
// BatchProcessFactory.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC BatchProcessFactory : public AbstractFactory
	{
	public:
		BatchProcessFactory () {};
		~BatchProcessFactory () {};

		StorageProduct* CreateStorageProduct ();
		DisplayProduct* CreateDisplayProduct ();
		ControlProduct* CreateControlProduct ();
	};
}
