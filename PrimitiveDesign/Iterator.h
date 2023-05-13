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
		Item () {};
		virtual ~Item () {};
	};

	class IAggregate
	{
	public:
		virtual ~IAggregate () {};
		virtual void Iterator () = 0;
	};

	class IIterator
	{
	public:
		virtual ~IIterator () {};
		virtual void HasNext () = 0;
		virtual void Next () = 0;
	};

	class Aggregate : public IAggregate
	{
	public:
		Aggregate () {};
		~Aggregate () {};
	};

	class Iterator : public IIterator
	{
	public:
		Iterator () {};
		~Iterator () {};

		void HasNext () {};
		void Next () {};

	private:
		std::vector<Aggregate> _aggregate;
	};
}