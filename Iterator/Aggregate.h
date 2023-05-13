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
	class IIterator;
	template<class T>
	class ItemIterator;

	template<class T>
	class IAggregate
	{
	public:
		virtual ~IAggregate () {};
		virtual IIterator<T>* Itr () = 0;
	};

	template<class T>
	class ItemAggregate : public IAggregate<T>
	{
	public:
		ItemAggregate () {};
		~ItemAggregate () {};

		void Add (T item)
		{
			_items.push_back (item);
		};

		T Get (int index)
		{
			return _items.at (index);
		};

		size_t Size ()
		{
			return _items.size ();
		};

		IIterator<T>* Itr ()
		{
			return new ItemIterator<T> (this);
		};

	private:
		std::vector<T> _items;
	};
}