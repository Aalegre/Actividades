#include <iostream>
#include "DynArray.h"

void main() {
	DynArray test1 = DynArray(43);
	DynArray test2 = DynArray(11,9);
	test1.push(4);
	test1.print();
	test1.pop();
	test1.print();
	test2.print();
	DynArray test3 = DynArray((int*)test2.data, test2.capacity);
	test3.resize(4);
	test3.push(2);
	test3.insert(2, 4);
	test3.print();
	test3.resize(15);
	test3.erase(2);
	test3.print();
	test3.shrink();
	test3.print();

	char end;
	std::cout << "Enter character to exit...";
	std::cin >> end;
}