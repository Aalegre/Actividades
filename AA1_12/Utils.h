#pragma once
#include <cstdlib>
#include <iostream>
namespace Utils {

	struct Array
	{
		int* data;
		int length;
	};

	void print(const Array& a) {
		for (size_t i = 0; i < a.length; i++)
		{
			std::cout << a.data[i] << ',' << ' ';
		}
		std::cout << 'S' << ':' << a.length;
		std::cout << std::endl;
	}
	Array generate(int length, int max) {
		int* newArray = new int[length];
		for (size_t i = 0; i < length; i++)
		{
			newArray[i] = rand() % max;
		}
		return { newArray, length };
	}
	Array generate(int length) {
		return generate(length, 1000);
	}

	Array copy(const Array &a) {
		int* newArray = new int[a.length];
		for (size_t i = 0; i < a.length; i++)
		{
			newArray[i] = a.data[i];
		}
		return { newArray, a.length};
	}

	Array copy(const Array& a, int length) {
		int* newArray = new int[length];
		for (size_t i = 0; i < length; i++)
		{
			if (i <= a.length)
				newArray[i] = a.data[i];
			else
				newArray[i] = -1;
		}
		return { newArray, length };
	}
}