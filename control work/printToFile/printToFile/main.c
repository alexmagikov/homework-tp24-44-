#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void) {
	FILE* fileToRead;
	fileToRead = fopen("fileToRead.txt", "r");
	FILE* fileToPrint;
	fileToPrint = fopen("fileToPrint.txt", "w");
	char string[10] = "";
	char stringToPrintAll[30] = "";
	int startIndex = 0;
	int endIndex = 10;
	while (fgets(string, 10, fileToRead) != NULL) {
		printf("%s", string);
		char* stringToPrint;
		stringToPrint = string;
		for (int i = startIndex; i < endIndex; i++) {
			stringToPrintAll[i] = stringToPrint[i];
		}
	}
	printf("%s", stringToPrintAll);
	//while()

	fclose(fileToRead);
	fclose(fileToPrint);
}