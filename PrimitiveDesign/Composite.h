//
// Composite.h
//

#pragma once

#include <vector>

namespace Primitive_Composite
{
    class Component
    {
    public:
        Component(int number) { _number = number; };
        virtual ~Component() {};

        virtual int GetNumber() { return _number; };

    protected:
        Component() = delete;
        int _number;
    };

    class Composite : public Component
    {
    public:
        Composite(int number) :Component(number) {};
        virtual ~Composite() {};

        void Add(Component* component)
        {
            _components.push_back(component);
        }

    private:
        Composite() = delete;
        std::vector<Component*> _components;
    };

    class Leaf : public Component
    {
    public:
        Leaf(int number) :Component(number) {};
        virtual ~Leaf() {};

    private:
        Leaf() = delete;
    };
}