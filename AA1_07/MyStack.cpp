#include <iostream>
#include "MyStack.h"

//CONSTRUCTORS
MyStack::MyStack() {
	data = std::vector<int>();
}

MyStack::MyStack(int size_) {
	data = std::vector<int>(size_);
}

MyStack::MyStack(int size_, int value_) {
	data = std::vector<int>(size_, value_);
}

MyStack::MyStack(const MyStack &stack_) {
	data = std::vector<int>(stack_.data);
}

//MODIFIERS
void MyStack::push(int i_) {
	data.push_back(i_);
}

int MyStack::pop() {
	int i_ = top();
	data.pop_back();
	return i_;
}

//READERS
bool MyStack::isEmpty() {
	return data.size() == 0;
}

int MyStack::top() {
	return data[data.size()-1];
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