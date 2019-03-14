#include <iostream>
#include "DynArray.h"

#pragma region Constructors
// constructors
DynArray::DynArray()// constructs the array by default
{
	capacity = DYN_ARRAY_DEFAULT_SIZE;
	size = 0;
	data = new int[capacity];
}
DynArray::DynArray(int _capacity)// creates the array with a defined size
{
	capacity = _capacity;
	size = 0;
	data = new int[capacity];
}
DynArray::DynArray(int _capacity, int value)// creates and initializes the elements of the array with a value
{
	capacity = _capacity;
	data = new int[capacity];
	size = capacity;
	for (int i = 0; i < capacity; i++)
	{
		data[i] = value;
	}
}
DynArray::DynArray(int* arr, int _size)// copy contructor
{
	capacity = _size;
	data = new int[capacity];
	size = capacity;
	for (int i = 0; i < capacity; i++)
	{
		data[i] = arr[i];
	}
}

#pragma endregion

#pragma region Iterator functions
	// iterator functions
int* DynArray::begin()// returns an iterator(pointer) to the first element
{
	return (int*)data[0];
}
int* DynArray::end()// returns an iterator(pointer) to the last element
{
	return (int*)data[size - 1];
}
#pragma endregion

#pragma region Capacity functions
	// capacity functions
void DynArray::resize(int n)// resizes the array so that it contains n elements
{
	int *dataNew = new int[n];
	capacity = n;
	if(size > n) size = n;
	for (int i = 0; i < n; i++)
	{
		dataNew[i] = data[i];
	}
	//delete[] data;
	data = dataNew;

}
void DynArray::reserve(int n)// requests the capacity to be at least enough to contain n elements
{
	if (capacity < n) {
		resize(n);
	}
}
void DynArray::shrink()// requests the array to reduce its capacity to fit its size
{
	if (capacity > size) {
		resize(size);
	}
}
bool DynArray::empty()// returns whether the array size is 0 or not
{
	return size == 0;
}
int DynArray::maxSize()// returns the maximum number of elements that the array can hold
{
	return capacity;
}
#pragma endregion

#pragma region Element access functions
	// element access functions
int& DynArray::operator[] (int n)// returns a reference to the element at position n in the array
{
	return data[n];
}
int& DynArray::front()// returns a reference to the first element in the array
{
	return data[0];
}
int& DynArray::back()// returns a reference to the last element in the array
{
	return data[size - 1];
}
#pragma endregion

#pragma region Modifiers functions
	// modifiers functions
void DynArray::push(int val)// adds a new element at the end of the array, after its current last element
{
	if (size < capacity) {
		data[size] = val;
		size++;
	}
	else {
		resize(capacity + 1);
		size = capacity;
		data[capacity - 1] = val;
	}
}
void DynArray::pop()// removes the last element effectively reducing the array size by one
{
	if (size > 0) size--;
}
void DynArray::insert(int position, int val)// a new element is inserted before the element at the specified position
{
	int *secondHalf = new int[capacity - (position)];
	for (int i = 0; i < capacity - (position); i++)
	{
		secondHalf[i] = data[(position) + i];
	}
	if (size < capacity) {
		data[position] = val;
		for (int i = 0; i < capacity - (position); i++)
		{
			data[(position + 1)+i] = secondHalf[i];
		}
		size++;
	}
	else {
		int *firstHalf = new int[position];
		for (int i = 0; i < position; i++)
		{
			firstHalf[i] = data[i];
		}
		data = new int[capacity + 1];
		for (int i = 0; i < position; i++)
		{
			data[i] = firstHalf[i];
		}
		data[position] = val;
		for (int i = 0; i < capacity - (position); i++)
		{
			data[(position + 1) + i] = secondHalf[i];
		}
		capacity++;
		size++;
	}
}
void DynArray::erase(int position)// removes from the array a single element
{
	int *firstHalf = new int[position];
	for (int i = 0; i < position; i++)
	{
		firstHalf[i] = data[i];
	}

	int *secondHalf = new int[capacity - (position)];
	for (int i = 0; i < capacity - (position + 1); i++)
	{
		secondHalf[i] = data[(position + 1)+i];
	}

	data = new int[capacity];
	for (int i = 0; i < position; i++)
	{
		data[i] = firstHalf[i];
	}
	for (int i = 0; i < capacity - (position); i++)
	{
		data[(position) + i] = secondHalf[i];
	}
	size--;
}
void DynArray::erase(int first, int last)// removes from the array a range of elements
{
	size = last - first;
}
void DynArray::clear()// removes all elements from the array leaving it with a size of 0
{
	//delete[] data;
	//capacity = 0;
	size = 0;
}
#pragma endregion

#pragma region Utils functions	
// utils functions
void DynArray::fill(int *first, int *last, int value)// assigns the given value to the elements in the range [first, last) (First included, last not)
{

}
void DynArray::copy(int *first, int *last, int *dest)// copies all elements in the range [first, last) to dest (First included, last not)
{

}
void DynArray::print()// print the array
{
	std::cout << "Array filled:	" << size << "/" << capacity << "\n";
	for (int i = 0; i < size; i++){
		std::cout << "Element: " << i << "	> " << data[i] << "\n";
	}
	if (size < capacity) {
		std::cout << "Still left	" << capacity - size << " empty spaces\n\n";
	}
	else {
		std::cout << "No empty spaces left\n\n";
	}
}
#pragma endregion