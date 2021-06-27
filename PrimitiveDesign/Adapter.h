//
// Adapter.h
//

#pragma once

namespace Primitive_Adapter
{
    class Adaptee
    {
    public:
        Adaptee() {};
        virtual ~Adaptee() {};

        bool Action() { return true; };
    };

    class Adapter
    {
    public:
        Adapter(Adaptee* adaptee) { _adaptee = adaptee; };
        virtual ~ Adapter() {};

        bool DoAction() { return _adaptee->Action(); };

    private:
        Adapter() { _adaptee = nullptr; };
        Adaptee* _adaptee;
    };
}