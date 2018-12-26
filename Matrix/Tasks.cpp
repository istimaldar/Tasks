// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Array.h"
#include "Cylinder.h"
#include "CustomString.h"

int main()
{
	std::cout << "-------------------------Matrices-------------------------" << std::endl;

	const auto first = Matrix(3, 3).with_random_values();
	const auto second = Matrix(3, 3).with_random_values();
	const Matrix third = first + second;

	std::cout << "First matrix:" << std::endl << first << "Second matrix:" << std::endl << second << "Result:" << std::
		endl << third << std::endl;

	std::cout << "-------------------------Arrays-------------------------" << std::endl;
	const auto first_a = Array(10).with_random_values();
	const auto second_a = Array(10).with_random_values();
	const Array sub_a = first_a - second_a;
	const Array add_a = first_a + second_a;
	std::cout << "First array:" << std::endl << first_a << std::endl << "Second array:" << std::endl << second_a << std
		::endl <<
		"Subtraction result:" << std::endl << sub_a << std::endl << "Addition result:" << std::endl << add_a << std::
		endl;

	std::cout << "-------------------------Shapes-------------------------" << std::endl;
	const auto cylinder = Cylinder(0, 0, 5, 0, 10);
	std::cout << "Shape:" << std::endl << cylinder << std::endl << "Radius:" << std::endl << cylinder.radius() << std::
		endl << "Square:" << std::
		endl << cylinder.square() << std::endl << "Volume:" << std::endl << cylinder.volume() << std::endl;

	std::cout << "-------------------------Strings-------------------------" << std::endl;
	const auto first_s = CustomString("123456789");
	const auto second_s = CustomString("1234");
	const int result_s = first_s - second_s;
	std::cout << "First string:" << std::endl << first_s << std::endl << "Second string:" << std::endl << second_s <<
		std::endl << "Subtraction result:" << std::endl << result_s << std::endl;

	system("pause");
}
