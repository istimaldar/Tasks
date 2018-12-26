#pragma once
#include "Circle.h"
class Cylinder :
	public Circle
{
public:
	Cylinder(double x1, double y1, double x2, double y2, double height);
	double height() const;
	void set_height(double height);
	double volume() const;
	friend std::ostream& operator<<(std::ostream& stream, const Cylinder& obj);
private:
	double height_;
};

