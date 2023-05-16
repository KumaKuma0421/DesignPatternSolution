//
// Bridge.h
//

#pragma once

namespace Primitive_Bridge
{
	class IImplementer
	{
	public:
		virtual ~IImplementer () {};
		virtual bool Action () = 0;
	};

	class AbstractBridge
	{
	public:
		AbstractBridge () { _implementer = nullptr; };
		virtual ~AbstractBridge () {};

		virtual bool Action () = 0;

	protected:
		IImplementer* _implementer;
	};

	class Implementer1 :public IImplementer
	{
	public:
		Implementer1 () {};
		~Implementer1 () {};

		bool Action () { return true; };
	};

	class Implementer2 :public IImplementer
	{
	public:
		Implementer2 () {};
		~Implementer2 () {};

		bool Action () { return true; };
	};

	class Bridge : public AbstractBridge
	{
	public:
		Bridge (IImplementer* implementer)
		{
			_implementer = implementer;
		};
		~Bridge () {};

		bool Action ()
		{
			return _implementer->Action ();
		};

	private:
		Bridge () = delete;
	};
}