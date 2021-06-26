//
// Shop.h
//

#pragma once

#include <string>
#include <map>
#include <vector>
#include "Material.h"
#include "Strategy.h"

namespace Sample
{
    typedef std::map<std::string, Material*> Materials;
    typedef std::map<std::string, Strategy*> Strategies;
    typedef std::vector<Material*> Cart;

    class VirtualShop final
    {
    public:
        static VirtualShop* Instance();
        void Prepare();
        void Stock(std::string item);
        bool Pickup(std::string item);
        int Check();
        Material* Factory(std::string item);

    protected:
        VirtualShop() {};
        ~VirtualShop() {};

        static VirtualShop* _instance;
        Materials _stock;
        Strategies _strategy;
        Cart _cart;
    };
}