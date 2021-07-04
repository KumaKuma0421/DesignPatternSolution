//
// Interpreter.h
//

#pragma once

#include <vector>
#include <string>

namespace GoF_Interpreter
{
    class AbstractExpression
    {
    public:
        AbstractExpression(std::string  expression)
        {
            _expression = expression;
        };

        virtual ~AbstractExpression() {};
        
        virtual bool Interpret() = 0;

        std::string GetExpression()
        {
            return _expression;
        };

    protected:
        std::string _expression;

    private:
        AbstractExpression() = delete;
    };

    class Operand :public AbstractExpression
    {
    public:
        Operand(std::string operand) :AbstractExpression(operand) {};
        ~Operand() {};

        bool Interpret();

    private:
        Operand() = delete;
    };

    class CountOperand : public Operand
    {
    public:
        CountOperand(std::string operand) : Operand(operand)
        {
            _number = std::stoi(operand);
        };

        ~CountOperand() {};

        int GetNumber() { return _number; };

        void SetNumber(int number)
        {
            _number = number;
            _expression = std::to_string(_number);
        };

    private:
        CountOperand() = delete;

        int _number;
    };

    class Operation :public AbstractExpression
    {
    public:
        Operation(std::string operation) :AbstractExpression(operation)
        {
            _NextOperation = nullptr;
        };

        virtual ~Operation() {};

        void SetOperand(Operand* operand) { _operands.push_back(operand); };
        
        Operand* GetOperand(int index = 0)
        {
            return _operands[index];
        };
        
        void Chain(Operation* operation) { _NextOperation = operation; };
        
        Operation* Next() { return _NextOperation; };

        bool Interpret();

    private:
        Operation() = delete;

        std::vector<Operand*> _operands;
        Operation* _NextOperation;
    };

    class Interpreter
    {
    public:
        Interpreter();
        virtual ~Interpreter() {};

        bool Load(std::string fileName);
        bool Interpret();
        bool Run();

    private:
        std::vector<std::string> _Commands;
        Operation* _FirstOperation;
        Operation* _CurrentOperation;
    };
}