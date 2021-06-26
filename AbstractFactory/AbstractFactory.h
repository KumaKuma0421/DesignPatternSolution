//
// AbstractFactory.h
//

#pragma once

#include <string>

namespace GoF_AbstractFactory
{
    class StorageProduct
    {
    public:
        StorageProduct();
        virtual ~StorageProduct();

        virtual bool Store(std::string data) = 0;
        virtual std::string Load() = 0;
    };

    class DisplayProduct
    {
    public:
        DisplayProduct();
        virtual ~DisplayProduct();

        virtual bool Show(std::string message) = 0;
    };

    class ControlProduct
    {
    public:
        ControlProduct();
        virtual ~ControlProduct();

        virtual bool Start() = 0;
        virtual bool Stop() = 0;
    };
    class AbstractFactory
    {
    public:
        AbstractFactory();
        virtual ~AbstractFactory();

        static AbstractFactory* CreateFactory(std::string type);

        virtual StorageProduct* CreateStorageProduct() = 0;
        virtual DisplayProduct* CreateDisplayProduct() = 0;
        virtual ControlProduct* CreateControlProduct() = 0;
    };
}