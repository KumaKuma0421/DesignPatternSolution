//
// Visitor.h
//

#pragma once

namespace Primitive_Visitor
{
    class Visitor;
    class ConcreteAcceptor1;
    class ConcreteAcceptor2;

    class Acceptor
    {
    public:
        Acceptor() {};
        virtual ~Acceptor() {};

        virtual void Accept(Visitor* visitor) = 0;
        virtual void Action() = 0;
    };

    class Visitor
    {
    public:
        Visitor() {};
        virtual ~Visitor() {};

        virtual void Visit(ConcreteAcceptor1* acceptor) = 0;
        virtual void Visit(ConcreteAcceptor2* acceptor) = 0;
    };

    class ConcreteAcceptor1 : public Acceptor
    {
    public:
        ConcreteAcceptor1() {};
        ~ConcreteAcceptor1() {};

        void Accept(Visitor* visitor) { visitor->Visit(this); };
        void Action() {};
    };

    class ConcreteAcceptor2 : public Acceptor
    {
    public:
        ConcreteAcceptor2() {};
        ~ConcreteAcceptor2() {};

        void Accept(Visitor* visitor) { visitor->Visit(this); };
        void Action() {};
    };

    class ConcreteVisitor1 : public Visitor
    {
    public:
        ConcreteVisitor1() {};
        virtual ~ConcreteVisitor1() {};

        void Visit(ConcreteAcceptor1* acceptor) { acceptor->Action(); };
        void Visit(ConcreteAcceptor2* acceptor) { acceptor->Action(); };
    };

    class ConcreteVisitor2 : public Visitor
    {
    public:
        ConcreteVisitor2() {};
        virtual ~ConcreteVisitor2() {};

        void Visit(ConcreteAcceptor1* acceptor) { acceptor->Action(); };
        void Visit(ConcreteAcceptor2* acceptor) { acceptor->Action(); };
    };
}