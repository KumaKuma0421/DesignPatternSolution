//
// WindowDisplayProduct.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC WindowDisplayProduct : public DisplayProduct
	{
	public:
		WindowDisplayProduct () {};
		~WindowDisplayProduct () {};

		bool Show (std::string message);
	};
}