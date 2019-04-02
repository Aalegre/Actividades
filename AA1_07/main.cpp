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
	//std::cout << stack2.pop() << "\n";
	stack2.print();
	std::cout << stack1.isEmpty() << "\n";
	std::cout << stack1.top() << "\n";
	std::cout << stack1.size() << "\n";

	std::cout << "Stack Dyn array\n\n";

	MyStackDynArray stackDyn1;
	stackDyn1.print();
	MyStackDynArray stackDynTest = MyStackDynArray(10, 10);
	stackDynTest.print();
	MyStackDynArray stackDyn2 = MyStackDynArray(stackDynTest);
	stackDyn2.print();

	stackDyn1.push(12049);
	stackDyn1.print();
	//std::cout << stack2.pop() << "\n";
	stackDyn2.print();
	std::cout << stackDyn1.isEmpty() << "\n";
	std::cout << stackDyn1.top() << "\n";
	std::cout << stackDyn1.size() << "\n";
	std::cout << "Presione tecla para salir...";
	char exit;
	std::cin >> exit;
}