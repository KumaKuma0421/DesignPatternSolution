//
// CacheManager.h
// (Originator)
//

#pragma once

#include <string>
#include "CacheObject.h"

#define MAX_CACHE 500

namespace GoF_Memento
{
    class CacheManager
    {
    public:
        CacheManager();
        virtual ~CacheManager();

        CacheObject* CreateCacheObject(int rowNo, std::string data);
        void SetCacheObject(CacheObject* cache);

        std::string GetContent();

    private:
        CacheObject* _CacheObject;
    };
}