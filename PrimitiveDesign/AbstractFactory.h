//
// AbstractFactory.h
//

#pragma once

namespace Primitive_AbstractFactory
{
    class IProduct1
    {
    public:
        virtual bool Action1() = 0;
    };

    class IProduct2
    {
    public:
        virtual bool Action2() = 0;
    };

    class IFactory
    {
    public:
        virtual IProduct1* CreateProduct1() = 0;
        virtual IProduct2* CreateProduct2() = 0;
    };

    class ProductA1 : public IProduct1
    {
    public:
        ProductA1() {};
        ~ProductA1() {};

        bool Action1() { return true; };
    };

    class ProductA2 : public IProduct2
    {
    public:
        ProductA2() {};
        ~ProductA2() {};

        bool Action2() { return true; };
    };

    class FactoryA : public IFactory
    {
    public:
        FactoryA() {};
        ~FactoryA() {};

        IProduct1* CreateProduct1() { return new ProductA1(); };
        IProduct2* CreateProduct2() { return new ProductA2(); };
    };

    class ProductB1 : public IProduct1
    {
    public:
        ProductB1() {};
        ~ProductB1() {};

        bool Action1() { return true; };
    };

    class ProductB2 : public IProduct2
    {
    public:
        ProductB2() {};
        ~ProductB2() {};

        bool Action2() { return true; };
    };

    class FactoryB : public IFactory
    {
    public:
        FactoryB() {};
        ~FactoryB() {};

        IProduct1* CreateProduct1() { return new ProductB1(); };
        IProduct2* CreateProduct2() { return new ProductB2(); };
    };
}