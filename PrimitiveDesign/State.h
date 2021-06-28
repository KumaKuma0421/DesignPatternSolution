//
// State.h
//

#pragma once

namespace Primitive_State
{
    class State
    {
    public:
        State() {};
        virtual ~State() {};

        virtual void Action() = 0;
    };

    class ConcreteState1 : public State
    {
    public:
        ConcreteState1() {};
        ~ConcreteState1() {};

        void Action() {};
    };

    class ConcreteState2 : public State
    {
    public:
        ConcreteState2() {};
        ~ConcreteState2() {};

        void Action() {};
    };

    class Invoker
    {
    public:
        Invoker()
        {
            _state[0][0] = new ConcreteState1();
            _state[0][1] = new ConcreteState2();
            _state[1][0] = new ConcreteState2();
            _state[1][1] = new ConcreteState1();
            _status = 0;
        };
        virtual ~Invoker() {};

        virtual void Action(int event)
        {
            State* state = _state[event][_status];
            if (state)
            {
                state->Action();
                _status++;
                if (_status >= 2) _status = 0;
            }
        };

    private:
        State* _state[2][2];
        int _status;
    };
}