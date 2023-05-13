//
// Main.cpp
//

#include <iostream>
#include "Operation.h"
#include "Shapes.h"

using namespace GoF_Visitor;

int main (int argc, char** argv)
{
	Line line (Position (1, 1), Position (2, 2));
	Triangle triangle (Position (1, 1), Position (2, 1), Position (1, 2));
	Rectangle rectangle (Position (1, 1), Position (2, 1), Position (2, 2), Position (1, 2));

	ShiftOperation shift (4, 5);
	RotateOperation rotate (120);

	line.Draw ();
	line.Operate (&shift);
	line.Operate (&rotate);
	line.Draw ();

	triangle.Draw ();
	triangle.Operate (&shift);
	triangle.Operate (&rotate);
	triangle.Draw ();

	rectangle.Draw ();
	rectangle.Operate (&shift);
	rectangle.Operate (&rotate);
	rectangle.Draw ();

	std::cout << "Done." << std::endl;
}