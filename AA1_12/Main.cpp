#include <chrono>
#include "Search.h"

int main() {
	srand(time(0));

	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	Utils::Array rand100000_o = Utils::generate(100000, 10);
	Utils::Array rand100_o = Utils::copy(rand100000_o, 100);
	Utils::Array rand1000_o = Utils::copy(rand100000_o, 1000);
	Utils::Array rand10000_o = Utils::copy(rand100000_o, 10000);

	Utils::Array rand100_t;
	Utils::Array rand1000_t;
	Utils::Array rand10000_t;
	Utils::Array rand100000_t;

	Utils::Array searchArray;

#pragma region S1

	rand100_t = Utils::copy(rand100_o);
	rand1000_t = Utils::copy(rand1000_o);
	rand10000_t = Utils::copy(rand10000_o);
	rand100000_t = Utils::copy(rand100000_o);

	begin = std::chrono::high_resolution_clock::now();

	searchArray = Search::linearSearchMultiple4(rand100_t, 9);

	end = std::chrono::high_resolution_clock::now();

	Utils::print(rand100_t);
	Utils::print(searchArray);

	std::cout << "S1 100		ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "		ps: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "		ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;


#pragma endregion S1

	return 0;
}