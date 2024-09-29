#include <stdio.h>
#include "tests.h"
#include <stdlib.h>
#include <time.h>

int fibRecursion(unsigned int num) {
	if (num == 1) {
		return 0;
	}
	if (num == 2) {
		return 1;
	}
	return fibRecursion(num - 1) + fibRecursion(num - 2);
}

long long int fibIteration(unsigned int num) {
	if (num == 0) {
		return 0;
	}
	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 1;
	}
	long long int num1 = 0;
	long long int num2 = 1;
	long long int searchNum = 0;
	for (int i = 2; i < num; i++) {
		searchNum = num1 + num2;
		num1 = num2;
		num2 = searchNum;
	}
	return searchNum;
}

void main(void) {
	int numOfFib = 40;
	clock_t timeOfWorkFibIteration;
	timeOfWorkFibIteration = clock();
	long long int fibNum1 = fibIteration(numOfFib);
	timeOfWorkFibIteration = clock() - timeOfWorkFibIteration;
	printf("%lld ", fibNum1);
	printf("Time for iteration %f \n", (float)timeOfWorkFibIteration / CLOCKS_PER_SEC);
	clock_t timeOfWorkFibRecursion;
	timeOfWorkFibRecursion = clock();
	long long int fibNum2 = fibRecursion(numOfFib);
	timeOfWorkFibRecursion = clock() - timeOfWorkFibRecursion;
	printf("%lld ", fibNum2);
	printf("Time for recursion %f \n", (float)timeOfWorkFibRecursion / CLOCKS_PER_SEC);
}