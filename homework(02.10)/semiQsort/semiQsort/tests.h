#include <stdbool.h>
#include <stdio.h>


bool isSorted(int array[], int numOfElements, int pivot) {
	for (int i = 0; i < numOfElements; i++) {
		if (array[i] >= pivot) {
			for (int j = i; j < numOfElements; j++) {
				if (array[j] < pivot) {
					return false;
				}
			}
			break;
		}
	}
	return true;
}

bool isNormalNumOfElements(int numOfElements) {
	return (numOfElements > 0 && numOfElements < 10000);
}
