//
// FlyweightFactory.cpp
//

#include "FlyweightFactory.h"

using namespace GoF_Flyweight;

bool Flyweight::Initialize (std::string fileName)
{
	std::ifstream ifs (fileName);
	if (!ifs)
	{
		std::cout << "ファイルが見つかりません。:" << fileName << std::endl;
		return false;
	}

	std::string line;
	while (!ifs.eof ())
	{
		std::getline (ifs, line);

		if (line[0] == ';') continue;
		if (line.size () == 0) continue;

		size_t separater = line.find ('=');
		std::string key = line.substr (0, separater);
		std::string value = line.substr (separater + 1);
		_map[key] = value;
	}

	return true;

	return true;
}

Flyweight* FlyweightFactory::GetFlyweight (std::string key)
{
	Flyweight* flyweight = _container[key];

	if (flyweight == nullptr)
	{
		if (key == "Type1")
		{
			flyweight = new Flyweight (key);
			flyweight->Initialize (".\\Property1.txt");
		}
		else if (key == "Type2")
		{
			flyweight = new Flyweight (key);
			flyweight->Initialize (".\\Property2.txt");
		}
		else
			flyweight = nullptr;

		_container[key] = flyweight;
	}

	return flyweight;
}