//
// Operation.h
//

#pragma once

#include "Shapes.h"

namespace GoF_Visitor
{
	class Position;
	class Shape;
	class Line;
	class Triangle;
	class Rectangle;

	class Operation
	{
	public:
		Operation ();
		virtual ~Operation ();

		virtual bool DoOperation (Line* target) = 0;
		virtual bool DoOperation (Triangle* target) = 0;
		virtual bool DoOperation (Rectangle* target) = 0;
	};

	class ShiftOperation : public Operation
	{
	public:
		ShiftOperation (int x, int y);
		~ShiftOperation () {};

		bool DoOperation (Line* target);
		bool DoOperation (Triangle* target);
		bool DoOperation (Rectangle* target);

	private:
		ShiftOperation () = delete;
		bool DoOperationCore (Shape* target);

		int _x;
		int _y;
	};

	class RotateOperation : public Operation
	{
	public:
		RotateOperation (double radian);
		~RotateOperation () {};

		bool DoOperation (Line* target);
		bool DoOperation (Triangle* target);
		bool DoOperation (Rectangle* target);

	private:
		RotateOperation () = delete;
		double _radian;
	};

	// もし、拡大(Expand)が増えたなら・・・
}