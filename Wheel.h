#pragma once
#include <random>


class Wheel
{
private:
	int LowerBound;
	int UpperBound;

public:
	Wheel();
	Wheel(int, int);

	void setLowerBound(int);
	void setUpperBound(int);

	int Spin();
};