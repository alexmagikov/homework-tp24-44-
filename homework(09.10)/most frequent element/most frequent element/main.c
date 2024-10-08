#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int* num1, int* num2) {
    int swapVariable = *num1;
    *num1 = *num2;
    *num2 = swapVariable;
}

int hoarSort(int array[], int leftIndex, int rightIndex) {
    int pivot = array[rand() % (rightIndex - leftIndex) + leftIndex];
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
    return startIndex;
}

void qSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int separator = hoarSort(array, leftIndex, rightIndex);
        qSort(array, leftIndex, separator - 1);
        qSort(array, separator, rightIndex);
    }
}

int searchMostFreaqmentElement(int array[], int numOfElements) {
    int mostFreaqment = -1;
    int countOfFreaqmentMax = 0;
    int countOfFreaqment = 0;
    for (int i = 0; i < numOfElements - 1; i++) {
        countOfFreaqment++;
        if (array[i] != array[i + 1]) {
            if (countOfFreaqmentMax < countOfFreaqment) {
                countOfFreaqmentMax = countOfFreaqment;
                mostFreaqment = array[i];
            }
            //printf("%d %d %d %d \n", mostFreaqment, countOfFreaqment, countOfFreaqmentMax, i);
            countOfFreaqment = 0;
        }
    }
    countOfFreaqment++;
    if (countOfFreaqment > countOfFreaqmentMax) {
        mostFreaqment = array[numOfElements - 1];
    }
    return mostFreaqment;   
}

bool testForStandartValue1() {
    int array[5] = { 1,2,3,4,5 };
    return searchMostFreaqmentElement(array, 5) == 1;
}

bool testForEqualLastValue() {
    int array[20] = { 0,0,1,3,4,4,6,6,6,7,8,9,9,9,9,10,10,10,10,10};
    return searchMostFreaqmentElement(array, 20) == 10;
}

bool testForSrandartValue2() {
    int array[5] = { 1,1,2,2,3};
    return searchMostFreaqmentElement(array, 5) == 1;
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
    printf("Old array ");
	for (int i = 0; i < numOfElements; i++) {
		array[i] = rand() % (11);
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

void main(void) {
    srand(time(0));
	int* array = createArray(20);
    qSort(array, 0, 19);
    printf("Sorted array ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    if (testForSrandartValue2() && testForEqualLastValue() && testForStandartValue1()) {
        printf("The most freaqment element %d", searchMostFreaqmentElement(array, 20));
    }
    else {
        printf("tests were not performed");
    }
}
