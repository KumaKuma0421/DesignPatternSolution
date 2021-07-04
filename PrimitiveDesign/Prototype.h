//
// Prototype.h
//

#pragma once

namespace Primitive_Prototype
{
    class Prototype
    {
    public:
        Prototype()
        {
            _bActive = false;
            _iCounter = -1;
        };

        Prototype(const Prototype& obj)
        {
            Take(obj);
        };

        virtual ~Prototype() {};

        Prototype* Clone()
        {
            Prototype* clone = new Prototype();
            clone->Take(*this);
            return clone;
        };

        Prototype& operator = (const Prototype& obj)
        {
            Take(obj);
            return *this;
        };

        void SetActive(bool bActive) { _bActive = bActive; };
        bool GetActive() { return _bActive; };

        void SetCounter(int iCounter) { _iCounter = iCounter; };
        int GetCounter() { return _iCounter; };

    private:
        void Take(const Prototype& obj)
        {
            _bActive = obj._bActive;
            _iCounter = obj._iCounter;
        }

        bool _bActive;
        int _iCounter;
    };
}