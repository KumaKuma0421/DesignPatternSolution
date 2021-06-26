//
// Operation.cpp
//

#include "Operation.h"

using namespace GoF_Visitor;

Operation::Operation()
{

}

Operation::~Operation()
{

}

ShiftOperation::ShiftOperation(int x, int y)
{
	_x = x;
	_y = y;
}

bool ShiftOperation::DoOperation(Line* target)
{
	return DoOperationCore(target);
}

bool ShiftOperation::DoOperation(Triangle* target)
{
	return DoOperationCore(target);
}

bool ShiftOperation::DoOperation(Rectangle* target)
{
	return DoOperationCore(target);
}

bool ShiftOperation::DoOperationCore(Shape* target)
{
	for (int i = 0; i < target->GetPoint(); i++)
	{
		Position pos = target->GetPosition(i);
		pos.SetX(pos.GetX() + _x);
		pos.SetY(pos.GetY() + _y);
		target->SetPosition(i, pos);
	}
	return true;
}

RotateOperation::RotateOperation(double radian)
{
	_radian = radian;
}

bool RotateOperation::DoOperation(Line* target)
{
	return true;
}

bool RotateOperation::DoOperation(Triangle* target)
{
	return true;
}

bool RotateOperation::DoOperation(Rectangle* target)
{
	return true;
}