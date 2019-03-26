#pragma once
#include <string>
#include <vector>

struct MyStack{
	//DATA
	std::vector<int> data;

	//CONSTRUCTORS
	MyStack();
	MyStack(int size_);
	MyStack(int size_, int value_);
	MyStack(const MyStack &stack_);

	//MODIFIERS
	void push(int i_);
	int pop();

	//READERS
	bool isEmpty();
	int top();
	int size();
	void print();
};