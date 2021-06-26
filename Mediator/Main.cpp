//
// Main.cpp
//

#include <iostream>
#include "Mediator.h"
#include "Colleague.h"

using namespace GoF_Mediator;

int main(int argc, char** argv)
{
    RealMediator mediator;
    RealColleague colleague1("同僚１");
    RealColleague colleague2("同僚２");
    RealColleague colleague3("同僚３");

    colleague1.SetMediator(&mediator);
    colleague2.SetMediator(&mediator);
    colleague3.SetMediator(&mediator);
    mediator.AddColleague(&colleague1);
    mediator.AddColleague(&colleague2);
    mediator.AddColleague(&colleague3);

    colleague1.Run();
    colleague2.Run();
    colleague3.Run();

    std::cout << "Done." << std::endl;
}