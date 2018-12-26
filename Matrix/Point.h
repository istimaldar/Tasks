#pragma once
#include <ostream>

class Point
{
public:
	Point(double x, double y);
	double x() const;
	void set_x(double x);
	double y() const;
	void set_y(double y);
	friend std::ostream& operator<<(std::ostream& stream, const Point& obj);
private:
	double x_;
	double y_;
};

