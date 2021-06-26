//
// Prototype.h
//

#pragma once
#include <string>

namespace GoF_Prototype
{
    class Prototype
    {
    public:
        Prototype();
        Prototype(const Prototype& obj);
        virtual ~Prototype();

        void Clone(Prototype& obj);
        Prototype& operator = (const Prototype& obj);
        Prototype& operator << (const Prototype& obj);

        int GetID() { return _id; };
        void SetID(int id) { _id = id; };

    protected:
        int _id;
    };

    class ConcretePrototype : public Prototype
    {
    public:
        ConcretePrototype();
        ConcretePrototype(const ConcretePrototype& obj);
        ~ConcretePrototype();

        void Clone(ConcretePrototype& obj);
        ConcretePrototype& operator = (const ConcretePrototype& obj);
        ConcretePrototype& operator << (const ConcretePrototype& obj);

        std::string GetName() { return _name; };
        void SetName(std::string name) { _name = name; };

    private:
        std::string _name;
    };
}