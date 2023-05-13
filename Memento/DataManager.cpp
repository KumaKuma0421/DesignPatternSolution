//
// DataManager.cpp
//

#include "DataManager.h"

using namespace GoF_Memento;

bool DataManager::Get (int id, std::string& data)
{
	bool ret;
	CacheObject* cache = _container[id];

	if (cache)
	{
		data = GetFromCache (cache);
		ret = true;
	}
	else
	{
		data = GetFromFile (id);
		ret = false;
	}

	return ret;
}

void DataManager::Set (int id, std::string& data)
{
	CacheObject* cache = _manager->CreateCacheObject (id, data);
	_container[id] = cache;
}

std::string DataManager::GetFromCache (CacheObject* cache)
{
	_manager->SetCacheObject (cache);
	return _manager->GetContent ();
}

std::string DataManager::GetFromFile (int id)
{
	std::string temporary = "0000" + std::to_string (id);
	std::string fileName = temporary.substr (temporary.length () - 4) + ".txt";
	std::ifstream ifs (fileName);
	if (!ifs) return std::string ("");
	std::string data;
	std::string line;
	while (std::getline (ifs, line))
	{
		data += (line + "\n");
	}
	ifs.close ();
	Set (id, data);
	return data;
}