#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void swap(int* num1, int* num2) {
	int swapVariable = *num1;
	*num1 = *num2;
	*num2 = swapVariable;
}

void shellSort(int array[], int numOfElements) {
	int step = numOfElements;
	while (step != 1) {
		step /= 2;
		int currentIndex = step;
		while (currentIndex < numOfElements) {
			int sortedElementIndex = currentIndex;
			int sortedIndex = currentIndex - step;
			while (array[sortedElementIndex] < array[sortedIndex] && sortedIndex >= 0) {
				swap(&array[sortedElementIndex], &array[sortedIndex]);
				sortedIndex--;
				sortedElementIndex--;
			}
			currentIndex++;
		}
	}
}

bool isSorted(int array[], int numOfElements) {
	for (int i = 0; i < numOfElements - 1; i++) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}

bool testForNormalValues1() {
	int array[5] = { 2,3,1,4,5 };
	shellSort(array, 5);
	return isSorted(array, 5);
}

bool testForNormalValues2() {
	int array[5] = { 1,1,1,1,1 };
	shellSort(array, 5);
	return isSorted(array, 5);
}

bool testForBorderValues1() {
	int array[5] = { 1,2,3,4,5 };
	shellSort(array, 5);
	return isSorted(array, 5);
}

bool testForBorderValues2() {
	int array[5] = { 5,4,3,2,1 };
	shellSort(array, 5);
	return isSorted(array, 5);
}

bool testForBorderValues3() {
	int array[5] = { 1,1,3,2,1 };
	shellSort(array, 5);
	return isSorted(array, 5);
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
	printf("old array ");
	for (int i = 0; i < numOfElements; i++) {
		array[i] = rand() % (11);
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

void main(void) {
	srand(time(0));
	int numOfElements = 20;
	int* array = createArray(20);
	shellSort(array, numOfElements);
	if (testForNormalValues1() && testForNormalValues2() && testForBorderValues1() && testForBorderValues2() && testForBorderValues3()) {
		printf("new array ");
		for (int i = 0; i < numOfElements; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	else {
		printf("tests not completed");
	}
}