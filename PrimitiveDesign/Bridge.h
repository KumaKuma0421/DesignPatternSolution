//
// Bridge.h
//

#pragma once

namespace Primitive_Bridge
{
    class IImprementer
    {
    public:
        virtual bool Action() = 0;
    };

    class AbstractBridge
    {
    public:
        AbstractBridge() { _imprementer = nullptr; };
        virtual ~AbstractBridge() {};

        virtual bool Action() = 0;

    protected:
        IImprementer* _imprementer;
    };

    class Imprementer1 :public IImprementer
    {
    public:
        Imprementer1() {};
        virtual ~Imprementer1() {};

        bool Action() { return true; };
    };

    class Imprementer2 :public IImprementer
    {
    public:
        Imprementer2() {};
        virtual ~Imprementer2() {};

        bool Action() { return true; };
    };

    class Bridge : public AbstractBridge
    {
    public:
        Bridge(IImprementer* imprementer)
        {
            _imprementer = imprementer;
        };
        ~Bridge() {};

        bool Action()
        {
            return _imprementer->Action();
        };

    private:
        Bridge() = delete;
    };
}