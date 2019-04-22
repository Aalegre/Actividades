#include "MyList.h"

int main() {

	MyList l1;
	l1.Push_Back(10);
	l1.Pop_Back();
	l1.Push_Back(11);
	l1.Pop_Front();
	l1.Push_Back(10);
	l1.Push_Back(20);
	l1.Push_Back(30);
	l1.Push_Back(20);
	l1.Push_Back(10);
	l1.Push_Back(40),
		std::cout << "l1(10 20 30 20 10 40)" << l1 << std::endl;

	MyList l2(l1);

	l1.Pop_Back();
	std::cout << "l1(10 20 30 20 10)" << l1 << std::endl;

	l1.Pop_Front();
	std::cout << "l1(20 30 20 10)" << l1 << std::endl;
	std::cout << "l2(10 20 30 20 10 40)" << l2 << std::endl;
	std::cout << "Sum (100): " << l2.Front() + l2.Back() + l2.MaxElement() + l2.MinElement() << std::endl;;

	l1.Insert(500, 3);
	std::cout << "Sum (505): " << l1.GetElementPos(3) + l1.GetNumElements() << std::endl;;

	l2.Insert(10, l2.GetNumElements() - 1);
	l2.DeleteAll(10);
	std::cout << "l2(20 30 20 40)  " << l2 << std::endl;;

	l2.Delete(0);
	std::cout << "l2(30 20 40)  " << l2 << std::endl;;
	l2.Delete(2);
	std::cout << "l2(30 20)  " << l2 << std::endl;;
	l2.Delete(1);
	std::cout << "l2(30)  " << l2 << std::endl;;
	l2.Delete(0);
	std::cout << "l2(vacía)  " << l2 << std::endl;;

	l1.DeleteDuplicates();
	std::cout << "Sin duplicados l1(30 20 500 10) " << l1 << std::endl;

	return 0;
}