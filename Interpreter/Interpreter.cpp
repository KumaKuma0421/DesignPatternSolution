//
// Interpreter.cpp
//

#include <iostream>
#include <fstream>
#include <map>
#include "Interpreter.h"

using namespace GoF_Interpreter;

Interpreter::Interpreter()
{
    _FirstOperation = nullptr;
    _CurrentOperation = nullptr;
}

bool Interpreter::Load(std::string fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cout << "ファイルが見つかりません。:" << fileName << std::endl;
        return false;
    }

    std::string line;
    while (!ifs.eof())
    {
        std::getline(ifs, line);

        if (line[0] == ';') continue;
        if (line.size() == 0) continue;

        _Commands.push_back(line);
    }

    return true;
}

bool Interpreter::Interpret()
{
    size_t _currentLine = 0;

    while (_currentLine < _Commands.size())
    {
        std::string line = _Commands[_currentLine++];
        std::string operationString;
        std::string operandString1;
        std::string operandString2;

        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                operationString = line.substr(0, i);

                size_t start = i + 1;
                for (size_t j = start; j < line.size(); j++)
                {
                    if (line[j] == ' ')
                    {
                        operandString1 = line.substr(start, j - start);
                        operandString2 = line.substr(j + 1);
                    }
                }

                if (operandString1 == "") operandString1 = line.substr(start);

                break;
            }
        }

        std::cout << "Operation:" << operationString << std::endl;
        std::cout << " Operand1:" << operandString1 << std::endl;
        std::cout << " Operand2:" << operandString2 << std::endl;
        std::cout << std::endl;

        Operation* operation = new Operation(operationString);

        Operand* operand1 = new Operand(operandString1);
        operation->SetOperand(operand1);

        if (!operandString2.empty())
        {
            Operand* operand2 = new CountOperand(operandString2);
            operation->SetOperand(operand2);
        }

        if (_FirstOperation == nullptr)
        {
            _FirstOperation = operation;
            _CurrentOperation = operation;
        }
        else {
            _CurrentOperation->Chain(operation);
            _CurrentOperation = operation;
        }
    }

    return true;
}

bool Interpreter::Run()
{
    Operation* operation = _FirstOperation;
    std::map<std::string, Operation*> jumpLabel;

    do
    {
        operation->Interpret();

        // Loop index
        if (operation->GetExpression() == "loop")
        {
            Operand* operand = operation->GetOperand();
            jumpLabel[operand->GetExpression()] = operation;
        }

        // Loop operation
        if (operation->GetExpression() == "goto")
        {
            Operand* operand = operation->GetOperand();
            Operation* jump = jumpLabel[operand->GetExpression()];
            CountOperand* counter = dynamic_cast<CountOperand*>(jump->GetOperand(1));
            if (counter->GetNumber() > 0)
            {
                counter->SetNumber(counter->GetNumber() - 1);
                operation = jump;
                continue;
            }
        }

        if (operation->Next() != nullptr)
            operation = operation->Next();
        else
            operation = nullptr;

    } while (operation != nullptr);

    return true;
}

bool Operation::Interpret()
{
    std::cout << "[" << _expression << "] ";
    for (auto operand : _operands)
    {
        operand->Interpret();
    }
    std::cout << std::endl;

    return true;
}

bool Operand::Interpret()
{
    std::cout << "(" << _expression << ") ";
    return true;
}