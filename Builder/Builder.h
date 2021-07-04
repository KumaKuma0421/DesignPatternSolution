//
// Builder.h
//

#pragma once

#include <string>

namespace GoF_Builder
{
    class Builder
    {
    public:
        Builder() {};
        virtual ~Builder() {};

        virtual std::string Build() = 0;
    };

    class ConcreteBuilder : public Builder
    {
    public:
        ConcreteBuilder() {};
        ~ConcreteBuilder() {};

        std::string Build();
    };

    class WoodBuilder : public Builder
    {
    public:
        WoodBuilder() {};
        ~WoodBuilder() {};

        std::string Build();
    };

    class Maker
    {
    public:
        Maker() { _selectedBuilder = nullptr; };
        virtual ~Maker() {};

        void SelectBuilder(std::string builder);
        std::string GetPrint();

    private:
        Builder* _selectedBuilder;
    };
}