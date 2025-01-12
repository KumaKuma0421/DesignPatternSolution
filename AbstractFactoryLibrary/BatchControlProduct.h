//
// BatchControlProduct.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC BatchControlProduct : public ControlProduct
	{
	public:
		BatchControlProduct () {};
		~BatchControlProduct () {};

		bool Start ();
		bool Stop ();
	};
}
