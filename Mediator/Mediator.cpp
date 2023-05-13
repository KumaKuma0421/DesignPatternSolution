//
// Mediator.cpp
//

#include "Mediator.h"
#include "Colleague.h"

using namespace GoF_Mediator;

void RealMediator::Consultation (Colleague* colleague)
{
	for (Colleague* colleagueOther : _colleagues)
	{
		if (colleagueOther->GetName () != colleague->GetName ())
		{
			std::cout << colleague->GetName () << "‚©‚ç‚Ì‚¨Šè‚¢B" << std::endl;
			colleagueOther->Advice ("‚±‚ê‚â‚Á‚Ä—~‚µ‚¢B");
		}
	}
}