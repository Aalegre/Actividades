#include <ctime>
#include <chrono>
#include "Order.h"
#include "Search.h"
#include "Utils.h"


int main() {
	srand(time(0));

	std::chrono::time_point<std::chrono::steady_clock> begin;
	std::chrono::time_point<std::chrono::steady_clock> end;

	int* rand100_o = Utils::generate(100, 10000);
	int* rand1000_o = Utils::generate(1000, 10000);
	int* rand10000_o = Utils::generate(10000, 10000);
	int* rand100000_o = Utils::generate(100000, 10000);

	int* rand100_t;
	int* rand1000_t;
	int* rand10000_t;
	int* rand100000_t;

#pragma region BUBBLE

	#pragma region UNSORTED

		rand100_t = Utils::copy(rand100_o, 100);
		rand1000_t = Utils::copy(rand1000_o, 1000);
		rand10000_t = Utils::copy(rand10000_o, 10000);
		rand100000_t = Utils::copy(rand100000_o, 100000);


		begin = std::chrono::steady_clock::now();

		Order::bubbleSort(rand100_t, 100);

		end = std::chrono::steady_clock::now();

		std::cout << "BUBBLE_UNSORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::bubbleSort(rand1000_t, 1000);

		end = std::chrono::steady_clock::now();

		std::cout << "BUBBLE_UNSORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::bubbleSort(rand10000_t, 10000);

		end = std::chrono::steady_clock::now();

		std::cout << "BUBBLE_UNSORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::bubbleSort(rand100000_t, 100000);

		end = std::chrono::steady_clock::now();

		std::cout << "BUBBLE_UNSORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion UNSORTED

	#pragma region SORTED

			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_SORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_SORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion SORTED

	#pragma region ISORTED

			Order::inverse(rand100_t, 100);
			Order::inverse(rand1000_t, 1000);
			Order::inverse(rand10000_t, 10000);
			Order::inverse(rand100000_t, 100000);


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_ISORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_ISORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::bubbleSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "BUBBLE_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion ISORTED

#pragma endregion BUBBLE

#pragma region SELECTION

	#pragma region UNSORTED

		rand100_t = Utils::copy(rand100_o, 100);
		rand1000_t = Utils::copy(rand1000_o, 1000);
		rand10000_t = Utils::copy(rand10000_o, 10000);
		rand100000_t = Utils::copy(rand100000_o, 100000);


		begin = std::chrono::steady_clock::now();

		Order::selectionSort(rand100_t, 100);

		end = std::chrono::steady_clock::now();

		std::cout << "SELECTION_UNSORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::selectionSort(rand1000_t, 1000);

		end = std::chrono::steady_clock::now();

		std::cout << "SELECTION_UNSORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::selectionSort(rand10000_t, 10000);

		end = std::chrono::steady_clock::now();

		std::cout << "SELECTION_UNSORTED 10000	ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::selectionSort(rand100000_t, 100000);

		end = std::chrono::steady_clock::now();

		std::cout << "SELECTION_UNSORTED 10000	ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion UNSORTED

	#pragma region SORTED

			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_SORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_SORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion SORTED

	#pragma region ISORTED

			Order::inverse(rand100_t, 100);
			Order::inverse(rand1000_t, 1000);
			Order::inverse(rand10000_t, 10000);
			Order::inverse(rand100000_t, 100000);


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_ISORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_ISORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::selectionSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "SELECTION_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion ISORTED

#pragma endregion SELECTION

#pragma region INSERTION

	#pragma region UNSORTED

		rand100_t = Utils::copy(rand100_o, 100);
		rand1000_t = Utils::copy(rand1000_o, 1000);
		rand10000_t = Utils::copy(rand10000_o, 10000);
		rand100000_t = Utils::copy(rand100000_o, 100000);


		begin = std::chrono::steady_clock::now();

		Order::insertionSort(rand100_t, 100);

		end = std::chrono::steady_clock::now();

		std::cout << "INSERTION_UNSORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::insertionSort(rand1000_t, 1000);

		end = std::chrono::steady_clock::now();

		std::cout << "INSERTION_UNSORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::insertionSort(rand10000_t, 10000);

		end = std::chrono::steady_clock::now();

		std::cout << "INSERTION_UNSORTED 10000	ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


		begin = std::chrono::steady_clock::now();

		Order::insertionSort(rand100000_t, 100000);

		end = std::chrono::steady_clock::now();

		std::cout << "INSERTION_UNSORTED 10000	ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion UNSORTED

	#pragma region SORTED

			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_SORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_SORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_SORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion SORTED

	#pragma region ISORTED

			Order::inverse(rand100_t, 100);
			Order::inverse(rand1000_t, 1000);
			Order::inverse(rand10000_t, 10000);
			Order::inverse(rand100000_t, 100000);


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand100_t, 100);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_ISORTED 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand1000_t, 1000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_ISORTED 1000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand10000_t, 10000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


			begin = std::chrono::steady_clock::now();

			Order::insertionSort(rand100000_t, 100000);

			end = std::chrono::steady_clock::now();

			std::cout << "INSERTION_ISORTED 10000		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() <<  "		탎: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<  "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

	#pragma endregion ISORTED

#pragma endregion INSERTION


	return 0;
}