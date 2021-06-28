//
// TemplateMethod.h
//

#pragma once

namespace Primitive_TemplateMethod
{
    class TemplateMethod
    {
    public:
        TemplateMethod() {};
        virtual ~TemplateMethod() {};

        virtual bool Action()
        {
            bool ret;

            ret = Function1();
            if (ret) ret = Function2();
            if (ret) ret = Function3();

            return ret;
        };
        virtual bool Function1() = 0;
        virtual bool Function2() = 0;
        virtual bool Function3() = 0;
    };

    class ConcreteMethod : public TemplateMethod
    {
    public:
        ConcreteMethod() {};
        ~ConcreteMethod() {};

        bool Function1() { return true; };
        bool Function2() { return true; };
        bool Function3() { return true; };
    };
}