#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


char * removeNewLine(char* string) {
    string[strcspn(string, "\n")] = 0;
    return string;
}

int readFileLength(char* fileLocation) {
    int ch;
    int result = 1;
    FILE *fileData;

    fileData = fopen(fileLocation, "r");

    if (fileData == NULL) {
        puts("Fatal error; file not found");
        exit(1);
    }

    while(!feof(fileData))
    {
        ch = fgetc(fileData);
        if(ch == '\n')
        {
            result++;
        }
    }
    fclose(fileData);
    return result;
}

void readFile(int *arr, char* fileLocation) {
    char* line = NULL;
    int i = 0;
    FILE *fileData = NULL;
    size_t len = 0;
    ssize_t read;

    fileData = fopen(fileLocation, "r");

    // Check if the file exists
    if (fileData == NULL) {
        puts("Fatal error; file not found");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fileData)) != -1) {
        i++;
        arr[i] = atoi(line);
    }

    fclose(fileData);
    if (line)
        free(line);
}

int main() {
    int higher = 0;
    int previous = 0;
    int arr[2001];

    // Read the file, returns integer array
    readFile(arr, "../input/input1.txt");

    puts("Welcome to the Challenge One solver for Advent of Code [2021]!");

    // Loop over the numbers provided by the array
    foreach(int *i, arr) {
        if (previous == 0) {
            previous = arr[1];
        } else {
            if (*i == 0) {
                continue;
            }
            if (*i > previous) {
//                printf("%d was higher than %d\n", *i, previous);
                previous = *i;
                higher++;
            } else {
//                printf("%d was not higher than %d\n", *i, previous);
                previous = *i;
                continue;
            }
        }
    }

    printf("Result: %d", higher);
    return 0;
}
