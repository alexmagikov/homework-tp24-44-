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
	int endIndex = rightIndex;
	int startIndex = leftIndex;
	while (startIndex <= endIndex) {
		while (array[startIndex] < pivot) {
			startIndex++;
		}
		while (array[endIndex] >= pivot) {
			endIndex--;
		}
		if (startIndex <= endIndex) {
			if (array[startIndex] == array[endIndex]) {
				endIndex--;
			}
			else {
				swap(&array[startIndex], &array[endIndex]);
				startIndex++;
				endIndex--;
			}
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
	printf("      ");
	return array;
}

bool testForEqualFirstAndLastELement() {
	int testArray[5] = { 10,5,4,2,10 };
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 4);
	return isSorted(testArray, 5, pivotTestArray);
}

bool testForEqualSomeELement1() {
	int testArray[10] = { 3,9,0,9,1,2,5,3,9,4 };
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 9);
	return isSorted(testArray, 10, pivotTestArray);
}

bool testForEqualSomeELement2() {
	int testArray[10] = { 2,9,3,8,0,4,10,2,4,3};
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 9);
	return isSorted(testArray, 10, pivotTestArray);
}

bool testForEqualSomeELement3() {
	int testArray[10] = { 5,7,6,1,1,9,6,5,10,3 };
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 9);
	return isSorted(testArray, 10, pivotTestArray);
}

bool testForEqualFirstAndLast2ELement() {
	int testArray[5] = { 10,5,4,10,10 };
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 4);
	return isSorted(testArray, 5, pivotTestArray);
}

bool testForExtemeArray() {
	int testArray[5] = { 1,2,3,4,5 };
	int pivotTestArray = testArray[0];
	hoarSort(testArray, 0, 4);
	return isSorted(testArray, 5, pivotTestArray);
}

void main(void) {
	srand(time(0));
	int numOfElements = 0;
	printf("input num of elements ");
	scanf("%d", &numOfElements);
	if (isNormalNumOfElements(numOfElements)) {
	
		for (int i = 0; i < 20; i++) {
			int* array = createArray(numOfElements);
			int pivot = array[0];
			hoarSort(array, 0, numOfElements - 1);
		
			if (testForEqualFirstAndLastELement() && testForExtemeArray() && testForEqualFirstAndLast2ELement() && isSorted(array, numOfElements, pivot)
				&& testForEqualSomeELement1() && testForEqualSomeELement2() && testForEqualSomeELement3() ) {
				printf("Sorted array ");
				for (int i = 0; i < numOfElements; i++) {
					printf("%d ", array[i]);
				}
			}
			else {
				printf("func didnt sort");
			}
			printf("\n");
			
			free(array);

		}
		
	}
	else {
		printf("Not correct input data");
	}
}

