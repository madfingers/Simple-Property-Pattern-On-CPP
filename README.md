# Simple property pattern on C++

Simple implementation: 

```
template <class T, class C>
class Property {
	C* owner;
	T(C::*getter)();
	void(C::*setter)(T);
public:
	Property() : owner(), getter(), setter() {}
	Property(C* owner, T(C::*getter)(), void(C::*setter)(T)) : owner(owner), getter(getter), setter(setter) {}
	void Set(T value) const {
		(owner->*setter)(value);
	}
	T Get() const {
		return (owner->*getter)();
	}
	operator T() const {
		return Get();
	}
	const Property<T, C>& operator = (T value) const {
		Set(value);
		return *this;
	}
};
```

Simple using in custom classes:

```
#include "Property.h"
class Point {
	int x, y;
public:
	Point() : X(this, &Point::GetX, &Point::SetX),
                  Y(this, &Point::GetY, &Point::SetY) {}
	const Property<int, Point> X, Y;
private:
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int value) { x = value; }
	void SetY(int value) { y = value; }
};
```

Expected behavior:

```
#include "Point.h"

int main(int argc, char** argv) {

	Point point;

	//assign values 
	point.X = 2;
	point.Y = 5;

	//getting values
	int x = point.X;
	int y = point.Y;

	//compile error on trying reassign property instance
	//point.X = Property<int, Point>();
	//point.Y = Property<int, Point>();

	return 0;
}
```
