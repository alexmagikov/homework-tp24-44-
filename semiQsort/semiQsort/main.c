#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "stdbool.h"

int* semiQsort(int array[], int numOfElements) {
	int smallerIndex = 0;
	int biggestIndex = numOfElements - 1;
	int sortNum = array[0];
	while (array[smallerIndex] == array[biggestIndex]) {
		biggestIndex--;
	}
	while (smallerIndex < biggestIndex) {
		if (array[smallerIndex] >= sortNum && array[biggestIndex] <= sortNum && array[smallerIndex] != array[biggestIndex]) {
			array[smallerIndex] = array[biggestIndex] + array[smallerIndex];
			array[biggestIndex] = array[smallerIndex] - array[biggestIndex];
			array[smallerIndex] = array[smallerIndex] - array[biggestIndex];
			smallerIndex++;
			biggestIndex--;
		}
		if (array[smallerIndex] < sortNum) {
			smallerIndex++;
		}
		if (array[biggestIndex] > sortNum) {
			biggestIndex--;
		}
		for (int i = 0; i < numOfElements; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	return array;
}

int* createArray(int numElements) {
	int* array = (int*)malloc(numElements * sizeof(int));
	for (int i = 0; i < numElements; i++) {
		array[i] = rand() % (11);
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

void main(void) {
	srand(time(0));
	int numElements = 0;
	printf("input num of elements ");
	scanf("%d", &numElements);
	int* array = createArray(numElements);
	int* newArray = semiQsort(array, numElements);
	for (int i = 0; i < numElements; i++) {
		printf("%d ", newArray[i]);
	}
}

