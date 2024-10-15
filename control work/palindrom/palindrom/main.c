#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrom(char const* string) {

	int endIndex = strlen(string) - 2;
	int startIndex = 0;
	while (startIndex <= endIndex / 2) {
		while (string[startIndex] == ' ') {
			startIndex++;
		}
		while (string[endIndex] == ' ') {
			endIndex--;
		}
		if (string[startIndex] != string[endIndex]) {
			return false;
		}
		endIndex--;
		startIndex++;
	}
	return true;
}

bool testForNormalValues1() {
	char const string[] = "123321 ";
	return isPalindrom(string);
}

bool testForNormalValues2() {
	char const string[] = "1235321 ";
	return isPalindrom(string);
}

bool testForBorderValues1() {
	char const string[] = "111111 ";
	return isPalindrom(string);
}

bool testForBorderValues2() {
	char const string[] = "ß á Ó Ó ÿ ÿ ";
	return !isPalindrom(string);
}

bool testForBorderValues3() {
	char const string[] = "ß ÿ Ó Ó ÿ ß ";
	return isPalindrom(string);
}

void main(void) {
	char string[30] = "";
	printf("Input string max of 30 chars ");
	fgets(string, 30, stdin);
	if (testForNormalValues1() && testForNormalValues2() && testForBorderValues1() && testForBorderValues2() && testForBorderValues3()) {
		if (isPalindrom(string)) {
			printf("palindrom");
		}
		else {
			printf("not palindrom");
		}
	}
	else {
		printf("tests not completed");
	}

}