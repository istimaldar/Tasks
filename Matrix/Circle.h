#pragma once
#include "Point.h"
class Circle : public Point
{
public:
	Circle(double x1, double y1, double x2, double y2);
	double x2() const;
	void set_x2(double x2);
	double y2() const;
	void set_y2(double y2);
	double radius() const;
	double square() const;
	friend std::ostream& operator<<(std::ostream& stream, const Circle& obj);
private:
	double x2_;
	double y2_;
};

