#include <iostream>
#include "MyStack.h"

//		MyStack Vector

//CONSTRUCTORS
MyStack::MyStack() {
	//data = std::vector<int>();
}

MyStack::MyStack(int size_) {
	data.resize(size_);
}

MyStack::MyStack(int size_, int value_) {
	data.insert(data.begin(), value_, size_);
}

MyStack::MyStack(const MyStack &stack_) {
	data = stack_.data;
}

//MODIFIERS
void MyStack::push(int i_) {
	data.push_back(i_);
}

void MyStack::pop() {
	data.pop_back();
}

//int MyStack::pop() {
//	int i_ = top();
//	data.pop_back();
//	return i_;
//}

//READERS
bool MyStack::isEmpty() {
	return data.empty();
}

int MyStack::top() {
	return data.back();
}

int MyStack::size() {
	return data.size();
}

void MyStack::print() {
	std::cout << "Stack filled:	" << data.size() << "/" << data.capacity() << "\n";
	for (int i = 0; i < data.size(); i++) {
		std::cout << "Element: " << i << "	> " << data[i] << "\n";
	}
	if (data.size() < data.capacity()) {
		std::cout << "Still left	" << data.capacity() - data.size() << " empty spaces\n\n";
	}
	else {
		std::cout << "No empty spaces left\n\n";
	}
}

//		MyStack DynArray

//CONSTRUCTORS
MyStackDynArray::MyStackDynArray() {
	//data = std::vector<int>();
}

MyStackDynArray::MyStackDynArray(int size_) {
	data.resize(size_);
}

MyStackDynArray::MyStackDynArray(int size_, int value_) {
	data.resize(size_);
	data.size = size_;
	for (unsigned int i = 0; i < size_; i++)
	{
		data[i] = value_;
	}
}

MyStackDynArray::MyStackDynArray(const MyStackDynArray &stack_) {
	data.resize(stack_.data.size);
	data.size = stack_.data.size;
	for (unsigned int i = 0; i < stack_.data.size; i++)
	{
		data[i] = stack_.data.data[i];
	}
}

//MODIFIERS
void MyStackDynArray::push(int i_) {
	data.push(i_);
}

void MyStackDynArray::pop() {
	data.pop();
}

//int MyStack::pop() {
//	int i_ = top();
//	data.pop_back();
//	return i_;
//}

//READERS
bool MyStackDynArray::isEmpty() {
	return data.empty();
}

int MyStackDynArray::top() {
	return data.back();
}

int MyStackDynArray::size() {
	return data.size;
}

void MyStackDynArray::print() {
	std::cout << "Stack filled:	" << data.size << "/" << data.capacity << "\n";
	for (int i = 0; i < data.size; i++) {
		std::cout << "Element: " << i << "	> " << data[i] << "\n";
	}
	if (data.size < data.capacity) {
		std::cout << "Still left	" << data.capacity - data.size << " empty spaces\n\n";
	}
	else {
		std::cout << "No empty spaces left\n\n";
	}
}