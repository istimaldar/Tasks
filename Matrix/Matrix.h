#pragma once
#include <iostream>
#include <fstream>

class Matrix final
{
public:
	Matrix(int row_number, int column_number);
	Matrix(const Matrix &old_obj);
	double *operator[](int index) const;
	Matrix& operator+(const Matrix& obj) const;
	friend std::ostream& operator<<(std::ostream& stream, const Matrix &obj);
	Matrix& with_random_values();
	~Matrix();
private:
	double **matrix_data_;
	int row_number_;
	int column_number_;
};

