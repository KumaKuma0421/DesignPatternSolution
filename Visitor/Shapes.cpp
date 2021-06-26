//
// Shapes.cpp
//

#include "Shapes.h"

using namespace GoF_Visitor;

Position::Position()
{
	_x = -1;
	_y = -1;
}

Position::Position(int x, int y)
{
	_x = x;
	_y = y;
}

void Position::Set(int x, int y)
{
	_x = x;
	_y = y;
}

Shape::Shape()
{
	_point = 0;
	_pos = nullptr;
}

Shape::~Shape()
{
	if (_pos) delete[] _pos;
}

bool Shape::Draw()
{
	for (int i = 1; i < _point; i++)
	{
		printf(
			"LineTo(%d,%d)-(%d,%d)\n",
			_pos[i - 1].GetX(), _pos[i - 1].GetY(),
			_pos[i].GetX(), _pos[i].GetY());
	}

	return true;
};

Line::Line(Position first, Position last)
{
	_point = 2;
	_pos = new Position[_point]{ first, last };
}

bool Line::Operate(Operation* operation)
{
	return operation->DoOperation(this);
}

Triangle::Triangle(Position first, Position second, Position third)
{
	_point = 3;
	_pos = new Position[_point]{ first, second, third };
}

bool Triangle::Operate(Operation* operation)
{
	return operation->DoOperation(this);
}

Rectangle::Rectangle(Position first, Position second, Position third, Position forth)
{
	_point = 4;
	_pos = new Position[_point]{ first, second, third, forth };
}

bool Rectangle::Operate(Operation* operation)
{
	return operation->DoOperation(this);
}
