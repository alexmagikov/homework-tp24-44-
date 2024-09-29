#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include "tests.h"

int expForLine(unsigned int base,unsigned int degree) {
	int result = base;
	if (degree == 0) {
		return 1;
	}
	for (int i = 1; i < abs(degree); i++) {
		result *= base;
	}
	return result;
}

int expForLog(int base, int degree) {
	if (degree == 0) {
		return 1;
	}
	if (degree % 2 == 0) {
		int firstDel = expForLog(base, degree / 2);
		return firstDel * firstDel;
	}
	else {
		return  expForLog(base, degree - 1) * base;
	}
}

void main(void) {
	unsigned int base = 0;
	unsigned int degree = 0;
	printf("Input positive base num ");
	scanf("%d", &base);
	printf("Input positive degree num ");
	scanf("%d", &degree);
	if (isNormalInputData(base,degree)) {
		printf("%d", expForLog(base, degree));
	}
	else {
		printf("Not correct input data");
	}
}