//
// Mediator.h
//

#pragma once

#include <vector>

namespace Primitive_Mediator
{
    class Colleague;

    class Mediator
    {
    public:
        Mediator() {};
        virtual ~Mediator() {};

        virtual void Add(Colleague* colleague) { _colleagues.push_back(colleague); };
        virtual void Consultation() = 0;
        virtual void Kick() { Consultation(); };

    protected:
        std::vector<Colleague*> _colleagues;
    };

    class Colleague
    {
    public:
        Colleague() { _mediator = nullptr; };
        virtual ~Colleague() {};

        virtual void Advice() = 0;
        virtual void Set(Mediator* mediator) { _mediator = mediator; };
    
    private:
        Mediator* _mediator;
    };

    class ConcreteMediator : public Mediator
    {
    public:
        ConcreteMediator() {};
        ~ConcreteMediator() {};

        void Consultation()
        {
            for (auto colleague : _colleagues)
            {
                colleague->Advice();
            }
        };
    };

    class ConcreteColleague1 : public Colleague
    {
    public:
        ConcreteColleague1() {};
        ~ConcreteColleague1() {};

        void Advice() {};
    };

    class ConcreteColleague2 : public Colleague
    {
    public:
        ConcreteColleague2() {};
        ~ConcreteColleague2() {};

        void Advice() {};
    };
}