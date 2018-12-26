#include "pch.h"
#include "Array.h"
#include <algorithm>

Array::Array(int size) : size_(size)
{
	array_data_ = new double[size];
	for (auto i = 0; i < size; i++)
	{
		array_data_[i] = 0;
	}
}

Array::Array(const Array& old_obj) : size_(old_obj.size_)
{
	array_data_ = new double[size_];
	for (auto i = 0; i < size_; i++)
	{
		array_data_[i] = old_obj[i];
	}
}

double& Array::operator[](const int index) const
{
	return array_data_[index];
}

Array& Array::operator+(const Array& obj) const
{
	const int total_size = size_ + obj.size_;
	const auto result = new Array(total_size);

	for (auto i = 0; i < size_; i++)
	{
		(*result)[i] = array_data_[i];
	}
	for (auto i = 0; i < obj.size_; i++)
	{
		(*result)[size_ + i] = obj[i];
	}

	return *result;
}

Array& Array::operator-(const Array& obj) const
{
	const int size = std::min(size_, obj.size_);
	const auto buffer = new double[std::min(size_, obj.size_)];
	int result_size = 0;

	for (auto i = 0; i < size; i++)
	{
		if (array_data_[i] == obj[i])
		{
			buffer[result_size] = array_data_[i];
			result_size++;
		}
	}

	const auto result = new Array(result_size);
	for (auto i = 0; i < result_size; i++)
	{
		(*result)[i] = buffer[i];
	}
	delete[] buffer;

	return *result;
}

Array& Array::with_random_values()
{
	for (auto i = 0; i < size_; i++)
	{
		array_data_[i] = rand() % 10;
	}

	return  *this;
}

Array::~Array()
{
	delete[] array_data_;
}

std::ostream& operator<<(std::ostream& stream, const Array& obj)
{
	for (auto i = 0; i < obj.size_; i++)
	{
		stream << obj[i] << " ";
	}

	return stream;
}
