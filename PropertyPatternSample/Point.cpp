#include "Point.h"

Point::Point() :
	X(this, &Point::GetX, &Point::SetX),
	Y(this, &Point::GetY, &Point::SetY) {}

int Point::GetX() {
	return x;
}

void Point::SetX(int value) {
	x = value;
}

int Point::GetY() {
	return y;
}

void Point::SetY(int value) {
	y = value;
}
