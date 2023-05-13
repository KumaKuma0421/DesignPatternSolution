//
// Product.h
//

#pragma once

namespace GoF_FactoryMethod
{
	class Product
	{
	public:
		Product () {};
		virtual ~Product () {};
	};

	class ConcreteProduct : public Product
	{
	public:
		ConcreteProduct () {};
		~ConcreteProduct () {};
	};
}