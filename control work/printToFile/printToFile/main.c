#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void) {
	FILE* fileToRead;
	fileToRead = fopen("fileToRead.txt", "r");
	FILE* fileToPrint;
	fileToPrint = fopen("fileToPrint.txt", "w");
	char string[10] = "";
	char stringToPrintAll[30] = "";
	while (fgets(string, 10, fileToRead) != NULL) {
		printf("%s", string);
		char* stringToPrint;
		stringToPrint = string;
		for (int i = 0; i < 10; i++) {
			stringToPrintAll[i] = stringToPrint[i];
		}
		printf("%s", stringToPrintAll);
	}
	
	while()

	fclose(fileToRead);
	fclose(fileToPrint);
}