//
// ConsoleDisplayProduct.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC ConsoleDisplayProduct : public DisplayProduct
	{
	public:
		ConsoleDisplayProduct () {};
		~ConsoleDisplayProduct () {};

		bool Show (std::string message);
	};
}