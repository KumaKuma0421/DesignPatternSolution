//
// FactoryMethod.h
//

#pragma once

namespace Primitive_FactoryMethod
{
    class IProduct
    {
    public:
        virtual void Action() = 0;
    };

    class ICreator
    {
    public:
        virtual IProduct* CreateProduct() = 0;
    };

    class Product : public IProduct
    {
    public:
        Product() {};
        virtual ~Product() {};

        void Action() {};
    };

    class Creator : public ICreator
    {
    public:
        Creator() {};
        virtual ~Creator() {};

        IProduct* CreateProduct() { return new Product(); };
    };
}