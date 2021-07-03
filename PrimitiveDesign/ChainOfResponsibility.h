//
// ChainOfResponsibility.h
//

#pragma once

namespace Primitive_ChainOfResponsibility
{
    class Handler
    {
    public:
        Handler(Handler* handler) { _next = handler; };
        virtual ~Handler() {};

        bool Request()
        {
            if (_next) return _next->Request();
            else return false;
        };

    private:
        Handler() = delete;

        Handler* _next;
    };

    class ConcreteHandler1 : public Handler
    {
    public:
        ConcreteHandler1(Handler* handler) :Handler(handler) {};
        ~ConcreteHandler1() {};

    private:
        ConcreteHandler1() = delete;
    };

    class ConcreteHandler2 : public Handler
    {
    public:
        ConcreteHandler2(Handler* handler) :Handler(handler) {};
        ~ConcreteHandler2() {};

    private:
        ConcreteHandler2() = delete;
    };

    class ConcreteHandler3 : public Handler
    {
    public:
        ConcreteHandler3(Handler* handler) :Handler(handler) {};
        ~ConcreteHandler3() {};

    private:
        ConcreteHandler3() = delete;
    };
}