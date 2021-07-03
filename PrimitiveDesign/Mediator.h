//
// Mediator.h
//

#pragma once

#include <vector>

namespace Primitive_Mediator
{
    class AbstractColleague;

    class AbstractMediator
    {
    public:
        AbstractMediator() {};
        virtual ~AbstractMediator() {};

        virtual void Add(AbstractColleague* colleague) { _colleagues.push_back(colleague); };
        virtual void Consultation() = 0;
        virtual void Kick() { Consultation(); };

    protected:
        std::vector<AbstractColleague*> _colleagues;
    };

    class AbstractColleague
    {
    public:
        AbstractColleague() { _mediator = nullptr; };
        virtual ~AbstractColleague() {};

        virtual void Advice() = 0;
        virtual void Set(AbstractMediator* mediator) { _mediator = mediator; };

    private:
        AbstractMediator* _mediator;
    };

    class Mediator : public AbstractMediator
    {
    public:
        Mediator() {};
        ~Mediator() {};

        void Consultation()
        {
            for (auto colleague : _colleagues)
            {
                colleague->Advice();
            }
        };
    };

    class Colleague1 : public AbstractColleague
    {
    public:
        Colleague1() {};
        ~Colleague1() {};

        void Advice() {};
    };

    class Colleague2 : public AbstractColleague
    {
    public:
        Colleague2() {};
        ~Colleague2() {};

        void Advice() {};
    };
}