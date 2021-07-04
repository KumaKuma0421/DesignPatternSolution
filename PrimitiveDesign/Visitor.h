//
// Visitor.h
//

#pragma once

namespace Primitive_Visitor
{
    class IVisitor;
    class Acceptor1;
    class Acceptor2;

    class IAcceptor
    {
    public:
        virtual ~IAcceptor() {};
        virtual void Accept(IVisitor* visitor) = 0;
        virtual void Action() = 0;
    };

    class IVisitor
    {
    public:
        virtual ~IVisitor() {};
        virtual void Visit(Acceptor1* acceptor) = 0;
        virtual void Visit(Acceptor2* acceptor) = 0;
    };

    class Acceptor1 : public IAcceptor
    {
    public:
        Acceptor1() {};
        ~Acceptor1() {};

        void Accept(IVisitor* visitor) { visitor->Visit(this); };
        void Action() {};
    };

    class Acceptor2 : public IAcceptor
    {
    public:
        Acceptor2() {};
        ~Acceptor2() {};

        void Accept(IVisitor* visitor) { visitor->Visit(this); };
        void Action() {};
    };

    class Visitor1 : public IVisitor
    {
    public:
        Visitor1() {};
        ~Visitor1() {};

        void Visit(Acceptor1* acceptor) { acceptor->Action(); };
        void Visit(Acceptor2* acceptor) { acceptor->Action(); };
    };

    class Visitor2 : public IVisitor
    {
    public:
        Visitor2() {};
        ~Visitor2() {};

        void Visit(Acceptor1* acceptor) { acceptor->Action(); };
        void Visit(Acceptor2* acceptor) { acceptor->Action(); };
    };
}