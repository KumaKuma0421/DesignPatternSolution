//
// AbstractFactory.cpp
//

#include "pch.h"
#include "AbstractFactory.h"
#include "BatchProcessFactory.h"
#include "RealtimeProcessFactory.h"

using namespace GoF_AbstractFactory;

AbstractFactory* AbstractFactory::CreateFactory (std::string type)
{
	FUNCTION_BEGIN();

	AbstractFactory* response;

	if (type == "Batch")
	{
		std::cout << "new BatchProcessFactory" << std::endl;
		response = new BatchProcessFactory ();
	}
	else if (type == "Realtime")
	{
		std::cout << "new RealtimeProcessFactory" << std::endl;
		response = new RealtimeProcessFactory ();
	}
	else
	{
		std::cout << "Invalid parameter:" << type << std::endl;
		response = nullptr;
	}

	FUNCTION_END();
	return response;
}