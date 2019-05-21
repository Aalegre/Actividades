#pragma once
#include <cstdlib>
#include <iostream>
namespace Utils {
	void print(int a[], int length) {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << a[i] << ',' << ' ';
		}
		std::cout << std::endl;
	}
	int* generate(int length, int max) {
		int* newArray = new int[length];
		for (size_t i = 0; i < length; i++)
		{
			newArray[i] = rand() % max;
		}
		return newArray;
	}
	int* generate(int length) {
		return generate(length, 1000);
	}
	int* copy(int a[], int length) {
		int* newArray = new int[length];
		for (size_t i = 0; i < length; i++)
		{
			newArray[i] = a[i];
		}
		return newArray;
	}
}