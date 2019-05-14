#pragma once

namespace Search {

	int linearSearch(int a[], int length, int value) {

		int index = -1;

		for (int i = 0; i < length; i++) {
			if (value == a[i]) {
				index = i;
				break;
			}
		}
		return index;
	}

	int binarySearch(int a[], int length, int value)
	{
		int iLimit = 0;
		int sLimit = length - 1;
		int iMid;
		while (iLimit <= sLimit)
		{
			iMid = (iLimit + sLimit) / 2;
			if (a[iMid] == value) return iMid;
			else
				if (value < a[iMid]) sLimit = iMid - 1;
				else iLimit = iMid + 1;
		}
		return -1;
	}


	int * linearSearchAll(int a[], int length, int value) {

		int coincidences = 0;

		for (int i = 0; i < length; i++) {
			if (value == a[i]) {
				coincidences++;
			}
		}

		int* end = new int[coincidences];
		int pos = 0;
		for (int i = 0; i < coincidences + 1; i++) {
			if (value == a[i]) {
				end[pos] = a[i];
				pos++;
			}
		}

		return end;
	}
	
	int binarySearchR(int a[], int length, int value) {
		int iLimit = 0;
		int sLimit = length - 1;
		int iMid;
		while (iLimit <= sLimit)
		{
			iMid = (iLimit + sLimit) / 2;
			if (a[iMid] == value) {
				if(iMid == 0) return iMid;
				while (iMid > 0 && a[iMid] == a[iMid - 1])
					iMid--;
				return iMid;
			}
			else {
				if (value < a[iMid]) sLimit = iMid - 1;
				else iLimit = iMid + 1;
			}
		}
		return -1;
	}
		//esta búsqueda debe considerar el caso en que
		//pueden haber valores repetidos en el array devolviendo,
		//por lo tanto, la posición de la primera aparición del
		//valor buscado.
}