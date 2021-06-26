//
// Main.cpp
//

#include <iostream>
#include "Item.h"
#include "Aggregate.h"
#include "Iterator.h"

using namespace GoF_Iterator;

int main(int argc, char** argv)
{
    ItemAggregate<Item> items;

    for (int i = 0; i < 10; i++)
    {
        std::string itemName;

        itemName = "item No." + std::to_string(i + 1);
        Item item(i + 1, itemName);

        items.Add(item);
    }

    Iterator<Item>* itr = items.Itr();

    while (itr->HasNext())
    {
        Item item = itr->Next();
        std::cout << "Item id=" << item.GetID();
        std::cout << " name=" << item.GetName();
        std::cout << std::endl;
    }

    std::cout << "Done." << std::endl;
}

void sample()
{
    std::vector<Item> items;
    for (std::vector<Item>::iterator it = items.begin();
        it != items.end();
        ++it)
    {
        std::cout << it->GetID();
        std::cout << it->GetName();
        std::cout << std::endl;
    }

    for (auto item : items)
    {
        std::cout << item.GetID();
        std::cout << item.GetName();
        std::cout << std::endl;
    }
}