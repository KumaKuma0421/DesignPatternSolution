//
// AbstractFactory.h
//

#pragma once

namespace Primitive_AbstractFactory
{
    class Product1
    {
    public:
        Product1() {};
        virtual ~Product1() {};
    };

    class Product2
    {
    public:
        Product2() {};
        virtual ~Product2() {};
    };

    class AbstractFactory
    {
    public:
        AbstractFactory() {};
        virtual ~AbstractFactory() {};

        virtual Product1* CreateProduct1() = 0;
        virtual Product2* CreateProduct2() = 0;
    };

    class ConcreteProduct1 : public Product1
    {
    public:
        ConcreteProduct1() {};
        ~ConcreteProduct1() {};
    };

    class ConcreteProduct2 : public Product2
    {
    public:
        ConcreteProduct2() {};
        ~ConcreteProduct2() {};
    };

    class ConcreteFactory : public AbstractFactory
    {
    public:
        ConcreteFactory() {};
        ~ConcreteFactory() {};

        Product1* CreateProduct1() { return new ConcreteProduct1(); };
        Product2* CreateProduct2() { return new ConcreteProduct2(); };
    };
}