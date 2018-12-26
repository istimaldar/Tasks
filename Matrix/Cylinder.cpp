#include "pch.h"
#include "Cylinder.h"

Cylinder::Cylinder(double x1, double y1, double x2, double y2, double height) : Circle(x1, y1, x2, y2), height_(height)
{
}

double Cylinder::height() const
{
	return height_;
}

void Cylinder::set_height(double height)
{
	height_ = height;
}

double Cylinder::volume() const
{
	return square() * height();
}

std::ostream& operator<<(std::ostream& stream, const Cylinder& obj)
{
	stream << "Cylinder(base: " << static_cast<const Circle&>(obj) << ", height: " << obj.height() << ")";
	return stream;
}
