#include "Wheel.h"


Wheel::Wheel()
{
	LowerBound = 1;
	UpperBound = 10;

	srand(time(0));
}

Wheel::Wheel(int lower, int upper)
{
	LowerBound = lower;
	UpperBound = upper;

	srand(time(0));
}

void Wheel::setLowerBound(int lower) { LowerBound = lower; }

void Wheel::setUpperBound(int upper) { UpperBound = upper; }

int Wheel::Spin() { return rand() % (UpperBound - LowerBound + 1) + LowerBound; }
