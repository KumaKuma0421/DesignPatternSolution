//
// Mediator.h
//

#pragma once

#include <iostream>
#include <vector>
#include "Mediator.h"

namespace GoF_Mediator
{
	class Colleague;

	class Mediator
	{
	public:
		Mediator () {};
		virtual ~Mediator () {};

		virtual void AddColleague (Colleague* colleague) = 0;
		virtual void Consultation (Colleague* colleague) = 0;
	};

	class RealMediator : public Mediator
	{
	public:
		RealMediator () {};
		~RealMediator () {};

		void AddColleague (Colleague* colleague) { _colleagues.push_back (colleague); };
		void Consultation (Colleague* colleague);

	private:
		std::vector<Colleague*> _colleagues;
	};
}