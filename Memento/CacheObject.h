//
// CacheObject.h
// (Memento)
//

#pragma once

#include <string>

namespace GoF_Memento
{
	class CacheManager;

	class CacheObject
	{
	public:
		virtual ~CacheObject () {};

	private:
		CacheObject ();

		int _id;
		int _count;
		std::string _data;

		friend class CacheManager;
	};
}