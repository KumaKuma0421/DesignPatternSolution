//
// ChainOfResponsibility.h
//

#pragma once

namespace Primitive_ChainOfResponsibility
{
	class Handler
	{
	public:
		Handler (Handler* handler) { _next = handler; };
		virtual ~Handler () {};

		virtual bool Request ()
		{
			if (_next) return _next->Request ();
			else return false;
		};

	private:
		Handler () = delete;

		Handler* _next;
	};

	class ConcreteHandler1 : public Handler
	{
	public:
		ConcreteHandler1 (Handler* handler) :Handler (handler) {};
		~ConcreteHandler1 () {};

		bool Request ()
		{
			return Handler::Request ();
		};

	private:
		ConcreteHandler1 () = delete;
	};

	class ConcreteHandler2 : public Handler
	{
	public:
		ConcreteHandler2 (Handler* handler) :Handler (handler) {};
		~ConcreteHandler2 () {};

		bool Request ()
		{
			return Handler::Request ();
		};

	private:
		ConcreteHandler2 () = delete;
	};

	class ConcreteHandler3 : public Handler
	{
	public:
		ConcreteHandler3 (Handler* handler) :Handler (handler) {};
		~ConcreteHandler3 () {};

		bool Request ()
		{
			return Handler::Request ();
		};

	private:
		ConcreteHandler3 () = delete;
	};
}