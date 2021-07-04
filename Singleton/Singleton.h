//
// Singleton.h
//

#pragma once

namespace GoF_Singleton
{
    class Singleton final
    {
    public:
        static Singleton* getInstance()
        {
            if (_instance == nullptr) _instance = new Singleton();
            return _instance;
        }

        int GetValue1() { return _value1; };
        int GetValue2() { return _value2; };
        void SetValue1(int value1) { _value1 = value1; };
        void SetValue2(int value2) { _value2 = value2; };

    private:
        Singleton(const Singleton&) = delete;
        Singleton() = default;
        ~Singleton() = default;

        static Singleton* _instance;

        int _value1 = -1;
        int _value2 = -1;
    };

    Singleton* Singleton::_instance = nullptr;
}