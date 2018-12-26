#include "pch.h"
#include "Circle.h"

Circle::Circle(double x1, double y1, double x2, double y2) : Point(x1, y1), x2_(x2), y2_(y2)
{
}

double Circle::x2() const
{
	return x2_;
}

void Circle::set_x2(double x2)
{
	x2_ = x2;
}

double Circle::y2() const
{
	return y2_;
}

void Circle::set_y2(double y2)
{
	y2_ = y2;
}

double Circle::radius() const
{
	return sqrt(pow(x2() - x(), 2) + pow(y2() - y(), 2));
}

double Circle::square() const
{
	const double PI = atan(1.0) * 4;
	return PI * pow(radius(), 2);
}

std::ostream& operator<<(std::ostream& stream, const Circle& obj)
{
	stream << "Circle(center: " << static_cast<const Point&>(obj) << ", x2: " << obj.x2() << ", y2: " << obj.y2() << ")";
	return stream;
}
