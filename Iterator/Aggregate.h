//
// Aggregate.h
//

#pragma once

#include <vector>
#include "Item.h"
#include "Iterator.h"

namespace GoF_Iterator
{
    template<class T>
    class Iterator;
    template<class T>
    class ItemIterator;

    template<class T>
    class Aggregate
    {
    public:
        virtual Iterator<T>* Itr() = 0;
    };

    template<class T>
    class ItemAggregate : public Aggregate<T>
    {
    public:
        void Add(T item)
        {
            _items.push_back(item);
        };

        T Get(int index)
        {
            return _items.at(index);
        };

        size_t Size()
        {
            return _items.size();
        };

        Iterator<T>* Itr()
        {
            return new ItemIterator<T>(this);
        };

    private:
        std::vector<T> _items;
    };
}