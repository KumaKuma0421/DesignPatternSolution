//
// Decorator.h
//

#pragma once

namespace Primitive_Decorator
{
    class Component
    {
    public:
        Component() {};
        virtual ~Component() {};

        virtual bool Action() = 0;
    };

    class ConcreteComponent: public Component
    {
    public:
        ConcreteComponent() {};
        virtual ~ConcreteComponent() {};

        bool Action() { return true; };
    };

    class Decorator : public Component
    {
    public:
        Decorator(Component* component) { _component = component; };
        virtual ~Decorator() {};

        bool Action() { return true; };

    private:
        Decorator() = delete;

        Component* _component;
    };
}