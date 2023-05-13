//
// Shapes.h
//

#pragma once

#include <stdio.h>
#include "Operation.h"

namespace GoF_Visitor
{
	class Operation;

	class Position
	{
	public:
		Position ();
		Position (int x, int y);
		virtual ~Position () {};

		void Set (int x, int y);
		void SetX (int x) { _x = x; };
		void SetY (int y) { _y = y; };
		int GetX () { return _x; };
		int GetY () { return _y; };

	private:
		int _x;
		int _y;
	};

	// もし、Dotが増えたなら・・・

	class Shape
	{
	public:
		Shape ();
		virtual ~Shape ();

		int GetPoint () { return _point; };
		Position GetPosition (int i) { return _pos[i]; };
		void SetPosition (int i, Position pos) { _pos[i] = pos; }
		virtual bool Draw ();
		virtual bool Operate (Operation* operation) = 0;

	protected:
		int _point;
		Position* _pos;
	};

	class Line : public Shape
	{
	public:
		Line (Position first, Position last);
		~Line () {};

		virtual bool Operate (Operation* operation);
	};

	class Triangle : public Shape
	{
	public:
		Triangle (Position first, Position second, Position third);
		~Triangle () {};

		virtual bool Operate (Operation* operation);
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle (Position first, Position second, Position third, Position forth);
		~Rectangle () {};

		virtual bool Operate (Operation* operation);
	};
}