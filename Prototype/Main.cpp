//
// Main.cpp
//

#include <iostream>
#include "Prototype.h"

using namespace GoF_Prototype;

int main(int argc, char** argv)
{
    Prototype proto1;
    proto1.SetID(1);

    Prototype proto2(proto1);

    Prototype proto3;
    proto1.Clone(proto3);
    
    Prototype proto4;
    proto4 = proto1;

    Prototype proto5;
    proto5 << proto1;

    std::cout << "----------" << std::endl;
    std::cout << proto1.GetID() << std::endl;
    std::cout << proto2.GetID() << std::endl;
    std::cout << proto3.GetID() << std::endl;
    std::cout << proto4.GetID() << std::endl;
    std::cout << proto5.GetID() << std::endl;

    ConcretePrototype prot1;
    prot1.SetID(10);
    prot1.SetName("prot1");

    ConcretePrototype prot2(prot1);
    
    ConcretePrototype prot3;
    prot1.Clone(prot3);

    ConcretePrototype prot4;
    prot4 = prot1;

    ConcretePrototype prot5;
    prot5 << prot1;

    std::cout << "----------" << std::endl;
    std::cout << prot1.GetID() << std::endl;
    std::cout << prot1.GetName() << std::endl;
    std::cout << prot2.GetID() << std::endl;
    std::cout << prot2.GetName() << std::endl;
    std::cout << prot3.GetID() << std::endl;
    std::cout << prot3.GetName() << std::endl;
    std::cout << prot4.GetID() << std::endl;
    std::cout << prot4.GetName() << std::endl;
    std::cout << prot5.GetID() << std::endl;
    std::cout << prot5.GetName() << std::endl;
}
