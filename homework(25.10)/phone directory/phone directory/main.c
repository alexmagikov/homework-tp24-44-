#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int* array;
    int numOfElements;
} Array;

Array createArray() {
    Array result;
    FILE* file = fopen("data.txt", "r");
    int* array = NULL;
    char buffer[10];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        array = (int*)realloc(array, (index + 1) * sizeof(int));
        array[index] = atoi(buffer);
        index++;
    }

    fclose(file);
    result.array = array;
    result.numOfElements = index;
    return result;
}

void main(void) {
    FILE* file = fopen("numbers.txt", "r+");
    while (true) {
        int currentDo = 0;
        char name[20];
        char number[11];
        printf("\ninput command ");
        scanf("%d", &currentDo);
        switch (currentDo) {
        case 0:
            break;
        case 1:
            printf("input name ");
            scanf("%s", &name);
            printf("input number ");
            scanf("%s", &number);

            printf("%s %s", name, number);
        }
    
    }
}