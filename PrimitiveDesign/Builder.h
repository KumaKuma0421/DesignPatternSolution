//
// Builder.h
//

#pragma once

namespace Primitive_Builder
{
    class Product
    {
    public:
        Product() {};
        virtual ~Product() {};
    };

    class Builder
    {
    public:
        Builder() {};
        virtual ~Builder() {};

        virtual Product* Build() = 0;
    };

    class ConcreteBuilder : public Builder
    {
    public:
        ConcreteBuilder() {};
        ~ConcreteBuilder() {};

        Product* Build() { return new Product(); };
    };
}