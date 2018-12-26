#include "pch.h"
#include "Point.h"

Point::Point(double x, double y) : x_(x), y_(y)
{
}

double Point::x() const
{
	return x_;
}

void Point::set_x(double x)
{
	x_ = x;
}

double Point::y() const
{
	return y_;
}

void Point::set_y(double y)
{
	y_ = y;
}

std::ostream& operator<<(std::ostream& stream, const Point& obj)
{
	stream << "Point(x: " << obj.x() << ", y: " << obj.y() << ")";
	return stream;
}
