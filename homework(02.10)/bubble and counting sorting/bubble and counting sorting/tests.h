#include <stdbool.h>
#include <stdio.h>

bool isSorted(int array[], int numOfElements) {
	for (int i = 0; i < numOfElements-1; i++) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}