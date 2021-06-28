//
// Memento.h
//

#pragma once

#include <map>

namespace Primitive_Memento
{
    class Memento
    {
    public:
        virtual ~Memento() {};

    private:
        Memento() {};
        friend class Originator;
    };

    class Originator
    {
    public:
        Originator() { _memento = nullptr; };
        virtual ~Originator() {};

        Memento* CreateMemento() { return new Memento(); };
        void SetMemento(Memento* memento) { _memento = memento; };

    private:
        Memento* _memento;
    };

    class Caretaker
    {
    public:
        Caretaker() {};
        virtual ~Caretaker() {};

        void Set(int number, Memento* memento) { _container[number] = memento; };
        Memento* Get(int number) { return _container[number]; };

    private:
        std::map<int, Memento*> _container;
    };
}