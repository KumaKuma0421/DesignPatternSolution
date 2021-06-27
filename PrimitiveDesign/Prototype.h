//
// Prototype.h
//

#pragma once

namespace Primitive_Prototype
{
    class Prototype
    {
    public:
        Prototype() {};
        virtual ~Prototype() {}

        virtual Prototype* Clone() = 0;
    };

    class ConcretePrototype : public Prototype
    {
    public:
        ConcretePrototype() {};
        ~ConcretePrototype() {};
    
        Prototype* Clone()
        {
            Prototype* response = new ConcretePrototype();

            return response;
        };
    };
}