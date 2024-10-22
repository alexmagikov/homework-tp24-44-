#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void swap(int* num1, int* num2) {
	*num1 = *num2 + *num1;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

int searchNumberOfZeroElements(int array[], int numberOfElements) {
	int numberOfZeroElements = 0;
	for (int i = 0; i < numberOfElements; i++) {
		if (array[i] == 0) {
			numberOfZeroElements++;
		};
	};
	return numberOfZeroElements;
}

int* createArray(int numberOfElements) {
	int* array = (int*)malloc(numberOfElements * sizeof(int)); //выделение памяти для массива длиной numberOfElements
	return array;
}

bool isSimple(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int happyTickets(void) {
	int arrayOfPossibleAmounts[28] = {};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arrayOfPossibleAmounts[(i + j + k)]++;
			}
		}
	}
	int numOfHappyTickets = 0;
	for (int i = 0; i < 28; i++) {
		numOfHappyTickets = numOfHappyTickets + arrayOfPossibleAmounts[i] * arrayOfPossibleAmounts[i];
	}
	return numOfHappyTickets;
}

int searchNumOccurence(char const *string1, char const *string2) {
	int numOfOccurence = 0;
	int lengthString1 = strlen(string1) - 1;
	int lengthString2 = strlen(string2) - 1;
	int index = 0;
	while (index < lengthString1) {
		bool isOccurence = true;
		for (int j = 0; j < lengthString2; j++) {
			if (string1[index + j] != string2[j]) {
				isOccurence = false;
				break;
			}
		}
		if (isOccurence) {
			numOfOccurence++;
		}
		index += lengthString2;
	}
	return numOfOccurence;
}

void swapPartOfArray(int array[], int startIndex, int finshIndex) {
	if ((finshIndex - startIndex + 1) % 2 == 0) {
		int numPairs = 0;
		while (numPairs != (finshIndex - startIndex + 1) / 2 ) {
			swap(&array[startIndex + numPairs], &array[finshIndex - numPairs]);
			numPairs++;
		}
	}
	else {
		int numPairs = 0;
		while (numPairs != (finshIndex - startIndex) / 2) {
			swap(&array[startIndex + numPairs], &array[finshIndex - numPairs]);
			numPairs++;
		}
	}
}

int searchQuotient(int divisible, int divider) {
	if (divisible == 0 || divider == 0) {
		return 0;
	}
	if (divisible > 0 && divider > 0) { 
		int quotient = 0;
		while (divisible >= divider) {
			quotient++;
			divisible = divisible - abs(divider);
		}
		return quotient;
	}
	if (divisible > 0 && divider < 0) {
		int quotient = 0;
		while (divisible >= abs(divider)) {
			quotient--;
			divisible = divisible - abs(divider);
		}
		return quotient;
	}
	if (divisible < 0 && divider > 0){
		int quotient = 1;
		while (divider * quotient < abs(divisible)) {
			quotient++;
		}
		return -quotient;
	}
	if (divisible < 0 && divider < 0) {
		int quotient = 1;
		while (abs(divider) * quotient < abs(divisible)) {
			quotient++;
		}
		return quotient;
	}
}

bool isBalanced(char const *string) {
	int countParenthesis = 0;
	int index = 0;
	while (string[index] != '\0') {
		if (string[index] == '(') {
			countParenthesis++;
		}
		else if (string[index] == ')') {
			countParenthesis--;
		}
		if (countParenthesis < 0) {
			return false;
		}
		index++;
	}
	return countParenthesis == 0;
}

