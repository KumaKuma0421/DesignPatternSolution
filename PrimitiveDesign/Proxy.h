//
// Proxy.h
//

#pragma once

namespace Primitive_Proxy
{
    class ISubject
    {
    public:
        virtual ~ISubject() {};
        virtual bool Action() = 0;
        virtual bool HeavyAction() = 0;
    };

    class Subject : public ISubject
    {
    public:
        Subject() {};
        ~Subject() {};

        bool Action() { return true; };
        bool HeavyAction() { return true; };
    };

    class Proxy : public ISubject
    {
    public:
        Proxy() {};
        ~Proxy() {};

        bool Action() { return true; };
        bool HeavyAction()
        {
            Subject* subject = new Subject();
            bool response = subject->HeavyAction();
            delete subject;
            return response;
        };
    };
}