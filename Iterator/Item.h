//
// Item.h
//

#pragma once

#include <string>

namespace GoF_Iterator
{
	class Item final
	{
	public:
		Item () :Item (-1, "") {};
		Item (int id, std::string name)
		{
			_id = id;
			_name = name;
		};
		virtual ~Item () {};

		int GetID () { return _id; };
		std::string GetName () { return _name; };

		void SetID (int id) { _id = id; };
		void SetName (std::string name) { _name = name; }

	private:
		int _id;
		std::string _name;
	};
}