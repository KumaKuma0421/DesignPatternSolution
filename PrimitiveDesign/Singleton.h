//
// Singleton.h
//

#pragma once

namespace Primitive_Singleton
{
    class Singleton final
    {
    public:
        ~Singleton() {};

        static Singleton* Instance()
        {
            if (_instance == nullptr) _instance = new Singleton();
            return _instance;
        };
    
    private:
        Singleton() {};

        static Singleton* _instance;
    };

    Singleton* Singleton::_instance;
}