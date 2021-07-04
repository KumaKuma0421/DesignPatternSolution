//
// Mediator.cpp
//

#include "Mediator.h"
#include "Colleague.h"

using namespace GoF_Mediator;

void RealMediator::Consultation(Colleague* colleague)
{
    for (Colleague* colleagueOther : _colleagues)
    {
        if (colleagueOther->GetName() != colleague->GetName())
        {
            std::cout << colleague->GetName() << "����̂��肢�B" << std::endl;
            colleagueOther->Advice("�������ė~�����B");
        }
    }
}