#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "tests.h"
#include <time.h>

void bubbleSort(int array[], int numOfElements) {
	for (int j = 0; j < numOfElements; j++) {
		for (int i = numOfElements - 1; i > j; i--) {
			if (array[i] < array[i - 1]) {
				array[i] = array[i - 1] + array[i];
				array[i - 1] = array[i] - array[i - 1];
				array[i] = array[i] - array[i - 1];
			}
		}
	}
}

void countSort(int array[], int numOfElements) {
	int max = 0;
	for (int i = 0; i < numOfElements; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	int* countArray = (int*)malloc((max+1) * sizeof(int));
	for (int i = 0; i < max + 1; i++) {
		countArray[i] = 0;
	}
	for (int i = 0; i < numOfElements; i++) {
		countArray[array[i]]++;
	}
	int index = 0;
	for (int i = 0; i < max + 1; i++) {
		if (countArray[i] > 0) {
			for (int j = 0; j < countArray[i]; j++) {
				array[index] = i;
				index++;
			}
		}
	}
	free(countArray);
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
	for (int i = 0; i < numOfElements; i++) {
		array[i] = rand() % (11);
		//printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

void main(void) {
	clock_t timeForWorkBubble;
	clock_t timeForWorkCount;
	srand(time(0));
	int numOfElements = 100000;
	int* array = createArray(numOfElements);
	timeForWorkBubble = clock();
	bubbleSort(array, numOfElements);
	timeForWorkBubble = clock() - timeForWorkBubble;
	timeForWorkCount = clock();
	countSort(array, numOfElements);
	timeForWorkCount = clock() - timeForWorkCount;
	printf("Time %f \n", (float)timeForWorkCount / CLOCKS_PER_SEC);
	if (isSorted(array,numOfElements)) {
		printf("Time %f \n", (float)timeForWorkBubble / CLOCKS_PER_SEC);
		printf("Time %f \n", (float)timeForWorkCount / CLOCKS_PER_SEC);
	}
	else {
		printf("not sorted");
	}
	free(array);

}