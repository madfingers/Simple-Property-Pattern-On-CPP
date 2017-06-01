#pragma once
#include "Property.h"
class Point {
	int x, y;
public:
	Point();
	const Property<int, Point> X;
	const Property<int, Point> Y;
private:
	int GetX();
	void SetX(int value);
	int GetY();
	void SetY(int value);
};