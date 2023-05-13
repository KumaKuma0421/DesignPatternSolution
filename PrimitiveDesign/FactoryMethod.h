//
// FactoryMethod.h
//

#pragma once

namespace Primitive_FactoryMethod
{
	class IProduct
	{
	public:
		virtual ~IProduct () {};
		virtual void Action () = 0;
	};

	class ICreator
	{
	public:
		virtual ~ICreator () {};
		virtual IProduct* CreateProduct () = 0;
	};

	class Product : public IProduct
	{
	public:
		Product () {};
		~Product () {};

		void Action () {};
	};

	class Creator : public ICreator
	{
	public:
		Creator () {};
		~Creator () {};

		IProduct* CreateProduct () { return new Product (); };
	};
}