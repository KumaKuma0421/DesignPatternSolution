//
// Decorator.h
//

#pragma once

namespace Primitive_Decorator
{
    class IComponent
    {
    public:
        virtual bool Action() = 0;
    };

    class Component : public IComponent
    {
    public:
        Component() {};
        virtual ~Component() {};

        bool Action() { return true; };
    };

    class Decorator : public IComponent
    {
    public:
        Decorator(IComponent* component) { _component = component; };
        virtual ~Decorator() {};

        bool Action() { return true; };

    private:
        Decorator() = delete;

        IComponent* _component;
    };
}