//
// Proxy.h
//

#pragma once

namespace Primitive_Proxy
{
    class Subject
    {
    public:
        Subject() {};
        virtual ~Subject() {};

        virtual bool Action() = 0;
        virtual bool HeavyAction() = 0;
    };

    class RealSubject : public Subject
    {
    public:
        RealSubject() {};
        ~RealSubject() {};

        bool Action() { return true; };
        bool HeavyAction() { return true; };
    };

    class Proxy
    {
    public:
        Proxy() {};
        virtual ~Proxy() {};

        bool Action() { return true; };
        bool HeavyAction()
        {
            RealSubject* subject = new RealSubject();
            bool response = subject->HeavyAction();
            delete subject;
            return response;
        };
    };
}