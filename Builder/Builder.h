//
// Builder.h
//

#pragma once

#include <string>

namespace GoF_Builder
{
	class Product
	{
	public:
		Product (std::string name);
		virtual ~Product () {};
		virtual std::string GetName () = 0;
		virtual std::string GetSpec () = 0;

	protected:
		std::string _name;

	private:
		Product () = delete;
	};

	class MetalProduct : public Product
	{
	public:
		MetalProduct (std::string name);
		~MetalProduct () {};
		std::string GetName ();
		std::string GetSpec ();

	private:
		MetalProduct () = delete;
	};

	class WoodProduct : public Product
	{
	public:
		WoodProduct (std::string name);
		~WoodProduct () {};
		std::string GetName ();
		std::string GetSpec ();

	private:
		WoodProduct () = delete;
	};

	class Builder
	{
	public:
		Builder () {};
		virtual ~Builder () {};

		virtual Product* BuildProduct () = 0;
	};

	class MetalBuilder : public Builder
	{
	public:
		MetalBuilder () {};
		~MetalBuilder () {};

		Product* BuildProduct ();
	};

	class WoodBuilder : public Builder
	{
	public:
		WoodBuilder () {};
		~WoodBuilder () {};

		Product* BuildProduct ();
	};
}