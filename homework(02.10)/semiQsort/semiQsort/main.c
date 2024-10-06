#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "tests.h"

void swap(int* num1, int* num2) {
	int swapVariable = *num1;
	*num1 = *num2;
	*num2 = swapVariable;
}

void hoarSort(int array[], int leftIndex, int rightIndex) {
	int pivot = array[leftIndex];
	swap(&array[leftIndex], &array[(leftIndex + rightIndex) / 2]);
	int endIndex = rightIndex;
	int startIndex = leftIndex;
	while (startIndex <= endIndex) {
		while (array[startIndex] < pivot) {
			startIndex++;
		}
		while (array[endIndex] > pivot) {
			endIndex--;
		}
		if (startIndex <= endIndex) {
			swap(&array[startIndex], &array[endIndex]);
			startIndex++;
			endIndex--;
		}
	}
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
	if (array == NULL) {
		return -1;
	}
	printf("Old array ");
	for (int i = 0; i < numOfElements; i++) {
		array[i] = rand() % (11);
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

bool testForEqualFirstAndLastELement() {
	int testArray[5] = { 10,5,4,2,10 };
	int pivotTestArray = testArray[0];
	semiQsort(testArray, 5);
	return isSorted(testArray, 5, pivotTestArray);
}

bool testForEqualFirstAndLast2ELement() {
	int testArray[5] = { 10,5,4,10,10 };
	int pivotTestArray = testArray[0];
	semiQsort(testArray, 5);
	return isSorted(testArray, 5, pivotTestArray);
}

bool testForExtemeArray() {
	int testArray[5] = { 1,2,3,4,5 };
	int pivotTestArray = testArray[0];
	semiQsort(testArray, 5);
	return isSorted(testArray, 5, pivotTestArray);
}

void main(void) {
	srand(time(0));
	int numOfElements = 0;
	printf("input num of elements ");
	scanf("%d", &numOfElements);
	if (isNormalNumOfElements(numOfElements)) {
		int* array = createArray(numOfElements);
		int pivot = array[0];
		hoarSort(array, 0, numOfElements - 1);
		if (testForEqualFirstAndLastELement() && testForEqualFirstAndLast2ELement() && isSorted(array, numOfElements, pivot)) {
			printf("Sorted array ");
			for (int i = 0; i < numOfElements; i++) {
				printf("%d ", array[i]);
			}
		}
		else {
			printf("func didnt sort");
		}
		free(array);
	}
	else {
		printf("Not correct input data");
	}
}

