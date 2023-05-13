//
// Receiver.h
//

#pragma once

#include <iostream>

namespace GoF_Command
{
	class IReceiver
	{
	public:
		virtual ~IReceiver () {};
		virtual bool Action (int param) = 0;
	};

	class RealReceiver : public IReceiver
	{
	public:
		RealReceiver () {};
		~RealReceiver () {};

		bool Action (int param);
	};
}