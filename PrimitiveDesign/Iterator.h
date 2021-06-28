//
// Iterator.h
//

#pragma once

#include <vector>

namespace Primitive_Iterator
{
    class Item
    {
    public:
        Item() {};
        virtual ~Item() {};
    };

    class Aggregate
    {
    public:
        Aggregate() {};
        virtual ~Aggregate() {};

        virtual void Iterator() = 0;
    };

    class Iterator
    {
    public:
        Iterator() {};
        virtual ~Iterator() {};

        virtual void HasNext() = 0;
        virtual void Next() = 0;
    };

    class ConcreteAggregate : public Aggregate
    {
    public:
        ConcreteAggregate() {};
        virtual ~ConcreteAggregate() {};
    };

    class ConcreteIterator : public Iterator
    {
    public:
        ConcreteIterator() {};
        ~ConcreteIterator() {};

        void HasNext() {};
        void Next() {};

    private:
        std::vector<ConcreteAggregate> _aggregate;
    };
}