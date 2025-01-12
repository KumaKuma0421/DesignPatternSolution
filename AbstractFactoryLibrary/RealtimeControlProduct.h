//
// RealtimeControlElement.h
//

#pragma once

#include "AbstractFactory.h"

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC RealtimeControlProduct : public ControlProduct
	{
	public:
		RealtimeControlProduct () {};
		~RealtimeControlProduct () {};

		bool Start ();
		bool Stop ();
	};
}