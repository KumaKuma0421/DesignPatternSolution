//
// DataManager.h
// (Caretaker)
//

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "CacheObject.h"
#include "CacheManager.h"

namespace GoF_Memento
{
    class DataManager
    {
    public:
        DataManager();
        virtual ~DataManager();

        bool Get(int id, std::string& data);
        void Set(int id, std::string& data);

    private:
        std::string GetFromCache(CacheObject* cache);
        std::string GetFromFile(int id);

        CacheManager* _manager;
        std::map<int, CacheObject*> _container;
    };
}