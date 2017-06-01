#include "Point.h"

int main(int argc, char** argv) {

	Point point;

	//assign values 
	point.X = 2;
	point.Y = 5;

	//getting values
	int x = point.X;
	int y = point.Y;

	//compile error if try reassing property instance
	//point.X = Property<int, Point>();
	//point.Y = Property<int, Point>();

	return 0;
}