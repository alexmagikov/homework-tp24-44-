#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void firstTask(void) {
	int numberOfElements;
	printf("Input int num of elements of array ");
	scanf("%d", &numberOfElements);
	int* array = createArray(numberOfElements); 
	for (int i = 0; i < numberOfElements; i++) {
		printf("Input int element ");
		scanf("%d", &array[i]);
	}

	int numberOfZeroElements;
	numberOfZeroElements = searchNumberOfZeroElements(array, numberOfElements);
	printf("Number of zero elements: %d", numberOfZeroElements);

	free(array);
}

void secondTask(void) {
	int a = 1;
	int b = 2; 
	printf("First num %d Second num %d \n", a, b);
	swap(&a, &b);
	printf("First num %d Second num %d", a, b);
}

void thirdTask(void) {
	int divisible = 0;
	int divider = 0; 
	printf("Input int divisible ");
	scanf("%d", &divisible);
	printf("Input int divider ");
	scanf("%d", &divider);
	printf("Incomplete quotient %d", searchQuotient(divisible, divider));
}

void fourthTask(void) {
	printf("Num of happy tickets %d", happyTickets());
}

void fifthTask(void) {
	char string[20] = "";
	printf("Input string with max of 20 letterss ");
	fgets(string, 20, stdin);
	if (isBalanced(string)) {
		printf("balanced");
	}
	else {
		printf("unbalanced");
	}
}

void sixthTask(void) {
	int num;
	int checkNum;
	printf("Input unsigned int num ");
	scanf("%d", &num);
	for (checkNum = 2; checkNum < num; checkNum++) {
		if (isSimple(checkNum)) {
			printf("%d ", checkNum);
		}
	}
}

void seventhTask(void) {
	char string1[20] = "";
	char string2[20] = "";
	printf("Input first string with  max 20 letters ");
	fgets(string1, 20, stdin);
	printf("Input shorter string with  max 20 letters ");
	fgets(string2, 20, stdin);
	printf("Num of occurence str2 in str1 %d", searchNumOccurence(string1, string2));
}

void eighthTask(void) {
	int numberOfElements;
	printf("Input int length of array ");
	scanf("%d", &numberOfElements);
	int* array = createArray(numberOfElements);
	for (int i = 0; i < numberOfElements; i++) {
		printf("Input int element ");
		scanf("%d", &array[i]);
	}
	int lengthPart1;
	printf("Input int length of part1  ");
	scanf("%d", &lengthPart1);
	swapPartOfArray(array, 0, lengthPart1 - 1);
	swapPartOfArray(array, lengthPart1, numberOfElements - 1);
	swapPartOfArray(array, 0, numberOfElements - 1);
	printf("New array ");
	for (int i = 0; i < numberOfElements; i++) {
		printf("%d ", array[i]);
	}
	free(array);
}	

void main(void) {
	sixthTask();
}