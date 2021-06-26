//
// Prototype.cpp
//

#include "Prototype.h"

using namespace GoF_Prototype;

Prototype::Prototype()
{
    _id = -1;
}

Prototype::Prototype(const Prototype& obj)
{
    _id = obj._id;
}

Prototype::~Prototype()
{

}

void Prototype::Clone(Prototype& obj)
{
    obj._id = _id;
}

Prototype& Prototype::operator = (const Prototype& obj)
{
    _id = obj._id;
    return *this;
}

Prototype& Prototype::operator << (const Prototype& obj)
{
    _id = obj._id;
    return *this;
}

// --------------------------------------------------------------------

ConcretePrototype::ConcretePrototype()
{

}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& obj)
{
    _id = obj._id;
    _name = obj._name;
}

ConcretePrototype::~ConcretePrototype()
{

}

void ConcretePrototype::Clone(ConcretePrototype& obj)
{
    obj._id = _id;
    obj._name = _name;
}

ConcretePrototype& ConcretePrototype::operator = (const ConcretePrototype& obj)
{
    _id = obj._id;
    _name = obj._name;
    return *this;
}

ConcretePrototype& ConcretePrototype::operator << (const ConcretePrototype& obj)
{
    _id = obj._id;
    _name = obj._name;
    return *this;
}
