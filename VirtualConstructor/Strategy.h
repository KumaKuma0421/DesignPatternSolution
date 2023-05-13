//
// Strategy.h
//

#pragma once

#include "Material.h"

namespace Sample
{
	class Strategy
	{
	public:
		Strategy () {};
		virtual ~Strategy () {};

		virtual Material* Make () = 0;
	};

	class IceCreamMaker : public Strategy
	{
	public:
		Material* Make ();
	};

	class MentosMaker : public Strategy
	{
	public:
		Material* Make ();
	};

	class CocaColaMaker : public Strategy
	{
	public:
		Material* Make ();
	};
}