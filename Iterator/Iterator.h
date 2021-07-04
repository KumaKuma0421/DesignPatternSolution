//
// Iterator.h
//

#pragma once

#include "Item.h"
#include "Aggregate.h"

namespace GoF_Iterator
{
    template<class T>
    class IAggregate;
    template<class T>
    class ItemAggregate;

    template<class T>
    class IIterator
    {
    public:
        virtual ~IIterator() {};
        virtual bool HasNext() = 0;
        virtual T Next() = 0;
    };

    template<class T>
    class ItemIterator : public IIterator<T>
    {
    public:
        ItemIterator(ItemAggregate<T>* aggregate)
        {
            _aggregate = aggregate;
            _index = 0;
        };

        ~ItemIterator() {};

        bool HasNext()
        {
            if (_index < _aggregate->Size()) return true;
            else return false;
        };

        T Next()
        {
            return _aggregate->Get(_index++);
        };

    private:
        ItemIterator() = delete;

        ItemAggregate<T>* _aggregate;
        size_t _index;
    };
}