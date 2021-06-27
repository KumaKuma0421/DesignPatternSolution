//
// Bridge.h
//

#pragma once

namespace Primitive_Bridge
{
    class AbstractImprementer
    {
    public:
        AbstractImprementer() {};
        virtual ~AbstractImprementer() {};

        virtual bool Action() = 0;
    };

    class AbstractBridge
    {
    public:
        AbstractBridge() { _imprementer = nullptr; };
        virtual ~AbstractBridge() {};

        virtual bool Action() = 0;

    protected:
        AbstractImprementer* _imprementer;
    };

    class ConcreteImprementer1 :public AbstractImprementer
    {
    public:
        ConcreteImprementer1() {};
        virtual ~ConcreteImprementer1() {};
        
        bool Action() { return true; };
    };

    class ConcreteImprementer2 :public AbstractImprementer
    {
    public:
        ConcreteImprementer2() {};
        virtual ~ConcreteImprementer2() {};

        bool Action() { return true; };
    };

    class ConcreteBridge : public AbstractBridge
    {
    public:
        ConcreteBridge(AbstractImprementer* imprementer)
        {
            _imprementer = imprementer;
        };
        ~ConcreteBridge() {};

        bool Action()
        {
            return _imprementer->Action();
        };

    private:
        ConcreteBridge() = delete;
    };
}