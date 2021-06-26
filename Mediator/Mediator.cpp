//
// Mediator.cpp
//

#include "Mediator.h"
#include "Colleague.h"

using namespace GoF_Mediator;

RealMediator::RealMediator()
{

}

RealMediator::~RealMediator()
{

}

void RealMediator::AddColleague(Colleague* colleague)
{
    _colleagues.push_back(colleague);
}

void RealMediator::Consultation(Colleague* colleague)
{
    for (Colleague* colleagueOther : _colleagues)
    {
        if (colleagueOther->GetName() != colleague->GetName())
        {
            std::cout << colleague->GetName() << "Ç©ÇÁÇÃÇ®äËÇ¢ÅB" << std::endl;
            colleagueOther->Advice("Ç±ÇÍÇ‚Ç¡Çƒó~ÇµÇ¢ÅB");
        }
    }
}