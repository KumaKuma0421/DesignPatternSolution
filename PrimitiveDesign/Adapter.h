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

    class IAdapter
    {
    public:
        virtual bool DoAction() = 0;
    };

    class Adapter1 : public IAdapter
    {
    public:
        Adapter1(Adaptee* adaptee) { _adaptee = adaptee; };
        virtual ~Adapter1() {};

        bool DoAction() { return _adaptee->Action(); };

    private:
        Adapter1() { _adaptee = nullptr; };
        Adaptee* _adaptee;
    };

    class Adapter2 : public IAdapter, Adaptee
    {
    public:
        Adapter2() {};
        ~Adapter2() {};

        bool DoAction() { return Action(); };
    };
}