#pragma once
#include <string>
#include <vector>
#include "DynArray.h"

class MyStack{
	//DATA
	std::vector<int> data;

public:
	//CONSTRUCTORS
	MyStack();
	MyStack(int size_);
	MyStack(int size_, int value_);
	MyStack(const MyStack &stack_);

	//MODIFIERS
	void push(int i_);
	void pop();

	//READERS
	bool isEmpty();
	int top();
	int size();
	void print();
};

class MyStackDynArray {
	//DATA
	DynArray data;

public:
	//CONSTRUCTORS
	MyStackDynArray();
	MyStackDynArray(int size_);
	MyStackDynArray(int size_, int value_);
	MyStackDynArray(const MyStackDynArray &stack_);

	//MODIFIERS
	void push(int i_);
	void pop();

	//READERS
	bool isEmpty();
	int top();
	int size();
	void print();
};