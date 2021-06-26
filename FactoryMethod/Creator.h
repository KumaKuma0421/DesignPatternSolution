//
// Creator.h
//

#pragma once

#include "Product.h"

namespace GoF_FactoryMethod
{
    class Creator
    {
    public:
        Creator();
        virtual ~Creator();

        virtual Product* CreateProduct() = 0;
    };

    class ConcreteCreator : public Creator
    {
    public:
        ConcreteCreator();
        ~ConcreteCreator();

        Product* CreateProduct();
    };
}