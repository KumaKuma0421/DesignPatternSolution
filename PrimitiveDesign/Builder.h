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

        bool Action() { return true; };
    };

    class IBuilder
    {
    public:
        virtual Product* Build() = 0;
    };

    class Builder : public IBuilder
    {
    public:
        Builder() {};
        ~Builder() {};

        Product* Build() { return new Product(); };
    };
}