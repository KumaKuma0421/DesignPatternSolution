//
// AbstractFactory.h
//

#pragma once

#include <iostream>
#include <string>

#ifdef ABSTRACTFACTORYLIBRARY_EXPORTS
  #ifndef DLL_DECLSPEC
    #define DLL_DECLSPEC __declspec(dllexport)
  #endif
#else
  #ifndef DLL_DECLSPEC
    #define DLL_DECLSPEC __declspec(dllimport)
  #endif
#pragma comment(lib, "AbstractFactoryLibrary.lib")
#endif

#define FUNCTION_BEGIN() std::cout << __FUNCTION__ << ":BEGIN" << std::endl
#define FUNCTION_END() std::cout << __FUNCTION__ << ":END" << std::endl;

namespace GoF_AbstractFactory
{
	class DLL_DECLSPEC StorageProduct
	{
	public:
		StorageProduct () {};
		virtual ~StorageProduct () {};

		virtual bool Store (std::string data) = 0;
		virtual std::string Load () = 0;
	};

	class DLL_DECLSPEC DisplayProduct
	{
	public:
		DisplayProduct () {};
		virtual ~DisplayProduct () {};

		virtual bool Show (std::string message) = 0;
	};

	class DLL_DECLSPEC ControlProduct
	{
	public:
		ControlProduct () {};
		virtual ~ControlProduct () {};

		virtual bool Start () = 0;
		virtual bool Stop () = 0;
	};

	class DLL_DECLSPEC AbstractFactory
	{
	public:
		AbstractFactory () {};
		virtual ~AbstractFactory () {};

		static AbstractFactory* CreateFactory (std::string type);

		virtual StorageProduct* CreateStorageProduct () = 0;
		virtual DisplayProduct* CreateDisplayProduct () = 0;
		virtual ControlProduct* CreateControlProduct () = 0;
	};
}