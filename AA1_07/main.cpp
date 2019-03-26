#include <iostream>
#include <ctime>
#include "MyStack.h"

void main() {
	MyStack stack1;
	stack1.print();
	MyStack stackTest = MyStack(10,10);
	stackTest.print();
	MyStack stack2 = MyStack(stackTest);
	stack2.print();

	stack1.push(12049);
	stack1.print();
	std::cout << stack2.pop() << "\n";
	stack2.print();
	std::cout << stack1.top() << "\n";
	std::cout << stack1.isEmpty() << "\n";
	std::cout << stack1.size() << "\n";
}