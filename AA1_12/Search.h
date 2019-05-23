#pragma once
#include <queue>
#include "Utils.h"
namespace Search {

	Utils::Array linearSearchMultiple1(const Utils::Array& a, int value) {	//3 + 4N

		int coincidences = 0;					//1

		for (int i = 0; i < a.length; i++) {	//N
			if (value == a.data[i]) {			//1
				coincidences++;					//1
			}
		}

		int* end = new int[coincidences];		//1
		int pos = 0;							//1
		for (int i = 0; i < a.length; i++) {	//N
			if (value == a.data[i]) {			//1
				end[pos] = i;					//1
				pos++;							//1
			}
		}

		return { end, coincidences};
	}

	Utils::Array linearSearchMultiple2(const Utils::Array& a, int value) {	//3 + 4N

		int coincidences = 0;					//1

		for (int i = 0; i < a.length; i++) {	//N
			if (value == a.data[i]) {			//1
				coincidences++;					//1
			}
		}

		int* end = new int[coincidences];		//1
		int pos = 0;							//1
		for (int i = 0; i < a.length; i++) {	//N
			if (value == a.data[i]) {			//1
				end[pos] = i;					//1
				pos++;							//1
			}
		}

		return { end, coincidences };
	}

	Utils::Array linearSearchMultiple3(const Utils::Array& a, int value) {	//3 + 4N

		int coincidences = 0;
		int* temp = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			if (value == a.data[i]) {
				temp[coincidences] = i;
				coincidences++;
			}
		}

		int* end = new int[coincidences];
		for (int i = 0; i < coincidences + 1; i++) {
			end[i] = temp[i];
		}

		delete[] temp;

		return { end, coincidences };
	}

	Utils::Array linearSearchMultiple4(const Utils::Array& a, int value) {

		int coincidences = 0;
		std::queue<int> findings;
		for (int i = 0; i < a.length; i++) {
			if (value == a.data[i]) {
				findings.push(i);
				coincidences++;
			}
		}

		int* end = new int[coincidences];
		for (int i = 0; i < coincidences; i++) {
			end[i] = findings.front();
			findings.pop();
		}

		return { end, coincidences };
	}
}
