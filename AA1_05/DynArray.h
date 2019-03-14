#pragma once

struct DynArray
{
#pragma region Data
	// atributes
	int	 capacity;											// actual size of the allocated memory
	int  size;												// current number of elements in the array
	int *data;												// pointer to the memory allocated in the Heap

	const int DYN_ARRAY_DEFAULT_SIZE{ 8 };					// initial constant size of the array memory
	const int DYN_ARRAY_MAX_SIZE{ 1073741823 };				// maximum constant size that the array memory can hold
#pragma endregion

#pragma region Constructors
	// constructors
	DynArray();												// constructs the array by default
	DynArray(int _capacity);									// creates the array with a defined size
	DynArray(int _capacity, int value);							// creates and initializes the elements of the array with a value
	DynArray(int* arr, int _size);							// copy contructor

#pragma endregion

#pragma region Iterator functions
	// iterator functions
	int* begin();											// returns an iterator(pointer) to the first element
	int* end();												// returns an iterator(pointer) to the last element
#pragma endregion

#pragma region Capacity functions
	// capacity functions
	void resize(int n);										// resizes the array so that it contains n elements
	void reserve(int n);									// requests the capacity to be at least enough to contain n elements
	void shrink();											// requests the array to reduce its capacity to fit its size
	bool empty();											// returns whether the array size is 0 or not
	int maxSize();											// returns the maximum number of elements that the array can hold
#pragma endregion

#pragma region Element access functions
	// element access functions
	int& operator[]	(int n);								// returns a reference to the element at position n in the array
	int& front();											// returns a reference to the first element in the array
	int& back();											// returns a reference to the last element in the array
#pragma endregion

#pragma region Modifiers functions
	// modifiers functions
	void push( int val);									// adds a new element at the end of the array, after its current last element
	void pop();												// removes the last element effectively reducing the array size by one
	void insert(int position,  int val);					// a new element is inserted before the element at the specified position
	void erase(int position);								// removes from the array a single element
	void erase(int first, int last);						// removes from the array a range of elements
	void clear();											// removes all elements from the array leaving it with a size of 0
#pragma endregion

#pragma region Utils functions	
// utils functions
	void fill(int *first, int *last, int value);			// assigns the given value to the elements in the range [first, last)
	void copy(int *first, int *last, int *dest);			// copies all elements in the range [first, last) to dest
	void print();											// print the array
#pragma endregion
};

