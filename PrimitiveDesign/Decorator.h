//
// Decorator.h
//

#pragma once

namespace Primitive_Decorator
{
	class IComponent
	{
	public:
		virtual ~IComponent () {};
		virtual bool Action () = 0;
	};

	class Component : public IComponent
	{
	public:
		Component () {};
		~Component () {};

		bool Action () { return true; };
	};

	class Decorator : public IComponent
	{
	public:
		Decorator (IComponent* component) { _component = component; };
		~Decorator () {};

		bool Action () { return _component->Action (); };

	private:
		Decorator () = delete;

		IComponent* _component;
	};
}