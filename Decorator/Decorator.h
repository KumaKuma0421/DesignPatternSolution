//
// TickCounter.h
//

#pragma once

#include <Windows.h>
#include <stdio.h>

namespace GoF_Decorator
{
	class Core
	{
	public:
		Core () {};
		virtual ~Core () {};

		virtual bool Action (DWORD dwParam) = 0;
	};

	class TickCounter : public Core
	{
	public:
		TickCounter (Core* core) { _core = core; };
		~TickCounter () {};

		bool Action (DWORD dwParam);

	private:
		TickCounter () = delete;

		Core* _core;
	};

	class FrequencyCounter : public Core
	{
	public:
		FrequencyCounter (Core* core);

		bool Action (DWORD dwParam);

	private:
		FrequencyCounter () = delete;

		Core* _core;
		LARGE_INTEGER _liFrequency;
	};

	class Execute : public Core
	{
	public:
		Execute () {};
		virtual ~Execute () {};

		bool Action (DWORD dwParam);
	};
}