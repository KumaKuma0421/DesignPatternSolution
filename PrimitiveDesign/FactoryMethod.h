//
// FactoryMethod.h
//

#pragma once

namespace Primitive_FactoryMethod
{
    class Product
    {
    public:
        Product() {};
        virtual ~Product() {};
    };

    class Creator
    {
    public:
        Creator() {};
        virtual ~Creator() {};

        virtual Product* CreateProduct() = 0;
    };

    class ConcreteProduct : public Product
    {
    public:
        ConcreteProduct() {};
        ~ConcreteProduct() {};
    };

    class ConcreteCreator : public Creator
    {
    public:
        ConcreteCreator() {};
        ~ConcreteCreator() {};

        Product* CreateProduct() { return new ConcreteProduct(); };
    };
}