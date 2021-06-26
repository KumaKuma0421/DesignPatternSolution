//
// Material.h
//

#pragma once

#include <string>

#define ICE_CREAM   "IceCream"
#define MENTOS      "Mentos"
#define COCA_COLA   "CocaCola"

namespace Sample
{
    class Material
    {
    public:
        Material(std::string id, std::string name, int price, int tax);
        virtual ~Material() {};

        std::string GetID() { return _id; };
        std::string GetName() { return _name; };
        int GetPrice() { return _price; };
        int GetTax() { return _tax; };
        int GetTaxPrice() { return _price + _price * _tax / 100; }

    private:
        std::string _id;
        std::string _name;
        int _price;
        int _tax;
    };
}