#include "MyList.h"
int main() {
	MyList list1;
	list1.Push_back(7);
	list1.Push_back(8);
	list1.Push_back(9);
	list1.Push_back(11);
	std::cout << list1 << '\n';
	MyList list2 = MyList(list1);
	list2.Push_front(1);
	list2.Change();
	std::cout << list2 << '\n';
	list2.Insert(42, 0);
	std::cout << list2 << '\n';
	std::cout << list2.MaxElement() << '\n';
	std::cout << list2.MinElement() << '\n';
	MyList list3;
	std::cout << list3.Empty() << '\n';
	list3 = list1;
	std::cout << list3 << '\n';
	return 0;
}