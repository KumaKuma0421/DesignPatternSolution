//
// Colleague.cpp
//

#include "Mediator.h"
#include "Colleague.h"

using namespace GoF_Mediator;

void RealColleague::Advice(std::string message)
{
    std::cout << "  " << GetName() << "‚Å‚·B" << std::endl;
    std::cout << "  " << message << std::endl;
}

void RealColleague::Run()
{
    _mediator->Consultation(this);
}