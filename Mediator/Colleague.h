//
// Colleague.h
//

#pragma once

#include <iostream>
#include <string>

namespace GoF_Mediator
{
    class Mediator;

    class Colleague
    {
    public:
        Colleague() { _mediator = nullptr; };
        virtual ~Colleague() {};

        void SetMediator(Mediator* mediator) { _mediator = mediator; };
        std::string GetName() { return _name; };

        virtual void Advice(std::string message) = 0;

    protected:
        Mediator* _mediator;
        std::string _name;
    };

    class RealColleague : public Colleague
    {
    public:
        RealColleague(std::string name) { _name = name; };
        ~RealColleague() {};

        void Advice(std::string message);

        void Run();

    private:
        RealColleague() = delete;
    };
}