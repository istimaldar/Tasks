#include "pch.h"
#include "CustomString.h"

CustomString::CustomString(const std::string& data)
{
	data_ = new std::string(data);
}

int CustomString::operator-(const CustomString& obj) const
{
	return data_->size() - obj.data_->size();
}

CustomString::~CustomString()
{
	delete data_;
}

std::ostream& operator<<(std::ostream& stream, const CustomString& obj)
{
	stream << (*obj.data_);
	return stream;
}
