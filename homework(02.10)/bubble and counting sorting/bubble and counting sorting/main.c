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

void bubbleSort(int array[], int numOfElements) {
	for (int j = 0; j < numOfElements; j++) {
		for (int i = numOfElements - 1; i > j; i--) {
			if (array[i] < array[i - 1]) {
				swap(&array[i], &array[i-1]);
			}
		}
	}
}

void countSort(int array[], int numOfElements) {
	int max = 0;
	int min = 0;
	for (int i = 0; i < numOfElements; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	int* countArray = (int*)malloc((abs(max) - min + 1) * sizeof(int));
	for (int i = 0; i <= (abs(max) - min); i++) {
		countArray[i] = 0;
	}
	for (int i = 0; i < numOfElements; i++) {
		countArray[array[i]-min]++;
	}
	int index = 0;
	for (int i = 0; i <= abs(max) - min; i++) {
		for (int j = 0; j < countArray[i]; j++) {
			array[index] = i + min;
			index++;
		}
	}
	free(countArray);
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
	for (int i = 0; i < numOfElements; i++) {
		array[i] = -10 + (rand() % (21));
	}
	printf("\n");
	return array;
}

void main(void) {
	clock_t timeForWorkBubble;
	clock_t timeForWorkCount;
	srand(time(0));
	int numOfElements = 100000;
	int* array1 = createArray(numOfElements);
	int* array2 = (int*)malloc(numOfElements * sizeof(int));
	for (int i = 0; i < numOfElements; i++) {
		array2[i] = array1[i];
	}
	timeForWorkBubble = clock();
	bubbleSort(array1, numOfElements);
	timeForWorkBubble = clock() - timeForWorkBubble;
	timeForWorkCount = clock();
	countSort(array2, numOfElements);
	timeForWorkCount = clock() - timeForWorkCount;
	if (isSorted(array1,numOfElements) && isSorted(array2, numOfElements)) {
		printf("Time %f \n", (float)timeForWorkBubble / CLOCKS_PER_SEC);
		printf("Time %f \n", (float)timeForWorkCount / CLOCKS_PER_SEC);
	}
	else {
		printf("not sorted");
	}
	free(array1);

}