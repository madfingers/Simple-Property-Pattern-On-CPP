#pragma once
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