#pragma once
#include <ostream>

class Array
{
public:
	explicit Array(int size);
	Array(const Array &old_obj);
	double &operator[](int index) const;
	Array& operator+(const Array& obj) const;
	Array& operator-(const Array& obj) const;
	friend std::ostream& operator<<(std::ostream& stream, const Array &obj);
	Array& with_random_values();
	~Array();
private:
	double *array_data_;
	int size_;
};

