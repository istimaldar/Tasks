#include "pch.h"
#include "Matrix.h"
#include <algorithm>
#include <stdexcept>

Matrix::Matrix(const int row_number, const int column_number) : row_number_(row_number), column_number_(column_number)
{
	matrix_data_ = new double*[row_number_];
	for (auto i = 0; i < row_number_; i++)
	{
		matrix_data_[i] = new double[column_number_];
		for (auto j = 0; j < column_number_; j++)
		{
			matrix_data_[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& old_obj) : row_number_(old_obj.row_number_), column_number_(old_obj.column_number_)
{
	matrix_data_ = new double*[row_number_];
	for (auto i = 0; i < row_number_; i++)
	{
		matrix_data_[i] = new double[column_number_];
		for (auto j = 0; j < column_number_; j++)
		{
			matrix_data_[i][j] = old_obj[i][j];
		}
	}
}

double* Matrix::operator[](const int index) const
{
	return matrix_data_[index];
}

Matrix& Matrix::operator+(const Matrix& obj) const
{
	if (row_number_ != obj.row_number_ || column_number_ != obj.column_number_)
	{
		throw std::invalid_argument("Unable to add matrices of different sizes");
	}

	const auto result = new Matrix(row_number_, column_number_);
	for (auto i = 0; i < row_number_; i++)
	{
		for (auto j = 0; j < column_number_; j++)
		{
			(*result)[i][j] = matrix_data_[i][j] + obj[i][j];
		}
	}

	return *result;
}

Matrix& Matrix::with_random_values()
{
	for (auto i = 0; i < row_number_; i++)
	{
		for (auto j = 0; j < column_number_; j++)
		{
			matrix_data_[i][j] = rand() % 100;
		}
	}

	return (*this);
}

Matrix::~Matrix()
{
	for (auto i = 0; i < row_number_; i++)
	{
		delete[] matrix_data_[i];
	}
	delete matrix_data_;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& obj)
{
	for (auto i = 0; i < obj.row_number_; i++)
	{
		for (auto j = 0; j < obj.column_number_; j++)
		{
			stream << obj[i][j] << " ";
		}
		stream << std::endl;
	}
	return stream;
}
