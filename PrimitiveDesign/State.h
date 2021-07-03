//
// State.h
//

#pragma once

namespace Primitive_State
{
    class IState
    {
    public:
        virtual void Action() = 0;
    };

    class State1 : public IState
    {
    public:
        State1() {};
        ~State1() {};

        void Action() {};
    };

    class State2 : public IState
    {
    public:
        State2() {};
        ~State2() {};

        void Action() {};
    };

    class Invoker
    {
    public:
        Invoker()
        {
            _state[0][0] = new State1();
            _state[0][1] = new State2();
            _state[1][0] = new State2();
            _state[1][1] = new State1();
            _status = 0;
        };
        virtual ~Invoker() {};

        virtual void Action(int event)
        {
            IState* state = _state[event][_status];
            if (state)
            {
                state->Action();
                _status++;
                if (_status >= 2) _status = 0;
            }
        };

    private:
        IState* _state[2][2];
        int _status;
    };
}