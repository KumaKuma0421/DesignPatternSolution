//
// TemplateMethod.h
//

#pragma once

namespace Primitive_TemplateMethod
{
    class AbstractTemplateMethod
    {
    public:
        AbstractTemplateMethod() {};
        virtual ~AbstractTemplateMethod() {};

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

    class TemplateMethod : public AbstractTemplateMethod
    {
    public:
        TemplateMethod() {};
        ~TemplateMethod() {};

        bool Function1() { return true; };
        bool Function2() { return true; };
        bool Function3() { return true; };
    };
}