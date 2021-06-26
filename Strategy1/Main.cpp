//
// Main.cpp
//

#include <iostream>
#include "Strategy1.h"

using namespace GoF_Strategy1;

void init(Container* container)
{
    std::string criteria;
    Strategy1* obj;

    obj = new BeginStrategy();
    criteria = "Begin";
    container->Add(criteria, obj);

    obj = new NextStrategy();
    criteria = "Next";
    container->Add(criteria, obj);

    obj = new PreviousStrategy();
    criteria = "Previous";
    container->Add(criteria, obj);

    obj = new EndStrategy();
    criteria = "End";
    container->Add(criteria, obj);
}

int main(int argc, char** argv)
{
    int ret = -1;
    Container* container;

    if (argc > 1)
    {
        std::string criteria;
        container = new Container();

        init(container);

        criteria = argv[1];
        Strategy1* obj = container->Get(criteria);
        if (obj)
        {
            ret = obj->Action(argv[2]);
        }
    }

    return ret;
}
