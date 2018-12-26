#pragma once
#include <string>

class CustomString
{
public:
	explicit CustomString(const std::string& data);
	friend std::ostream& operator<<(std::ostream& stream, const CustomString& obj);
	int operator-(const CustomString& obj) const;
	~CustomString();
private:
	std::string *data_;
};

