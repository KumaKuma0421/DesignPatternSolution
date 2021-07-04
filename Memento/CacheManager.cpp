//
// CacheManager.cpp
//

#include "CacheManager.h"

using namespace GoF_Memento;

CacheObject* CacheManager::CreateCacheObject(int rowNo, std::string data)
{
    CacheObject* cache = new CacheObject();
    cache->_id = rowNo;
    cache->_data = data;
    return cache;
}

void CacheManager::SetCacheObject(CacheObject* cache)
{
    _CacheObject = cache;
    _CacheObject->_count++;
    return;
}

std::string CacheManager::GetContent()
{
    return _CacheObject->_data;
}