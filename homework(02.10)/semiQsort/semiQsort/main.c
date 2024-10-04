#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "tests.h"

int* semiQsort(int array[], int numOfElements) {
	int smallerIndex = 0;
	int biggestIndex = numOfElements - 1;
	int sortNum = array[0];
	bool isEque = true;
	for (int i = 0; i < numOfElements-1; i++) {
		if (array[i] != array[i + 1]) {
			isEque = false;
			break;
		}
	}
	if (isEque) {
		return array;
	}
	while (array[smallerIndex] == array[biggestIndex]) {
		biggestIndex--;
	}
	while (smallerIndex < biggestIndex) {
		if (array[smallerIndex] >= sortNum && array[biggestIndex] <= sortNum && array[biggestIndex] != array[smallerIndex]) {
			array[smallerIndex] = array[biggestIndex] + array[smallerIndex];
			array[biggestIndex] = array[smallerIndex] - array[biggestIndex];
			array[smallerIndex] = array[smallerIndex] - array[biggestIndex];
			smallerIndex++;
			biggestIndex--;
		}
		if (array[smallerIndex] < sortNum) {
			smallerIndex++;
		}
		if (array[biggestIndex] >= sortNum) {
			biggestIndex--;
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
		semiQsort(array, numOfElements);
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

