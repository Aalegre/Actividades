#include <ctime>
#include "Order.h"
#include "Search.h"
#include "Utils.h"

int main() {
	srand(time(0));

	int* rand1 = Utils::generate(100000, 100000);

	Order::insertionSort(rand1, 100000);


	return 0;
}