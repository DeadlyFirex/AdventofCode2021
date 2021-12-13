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

#define BETWEEN(value, min, max) (value < max && value > min)

struct valueMap {
    unsigned int value, line;
};

char * removeNewLine(char* string) {
    string[strcspn(string, "\n")] = 0;
    return string;
}

int readFileLength(char* fileLocation) {
    unsigned int ch;
    int result = 1;
    FILE *fileData;

    fileData = fopen(fileLocation, "r");

    if (fileData == NULL) {
        puts("File not found; exiting");
        exit(EXIT_FAILURE);
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

void readFile(unsigned int *arr, char* fileLocation) {
    char* line = NULL;
    unsigned int i = 0;
    FILE *fileData = NULL;
    size_t len = 0;

    fileData = fopen(fileLocation, "r");

    // Check if the file exists
    if (fileData == NULL) {
        puts("File not found; exiting");
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fileData)) != -1) {
        i++;
        arr[i] = atoi(line);
    }

    fclose(fileData);
    if (line)
        free(line);
}

void readFileValueMap(struct valueMap *valueMap, char* fileLocation) {
    FILE *fileData = NULL;
    unsigned int i = 0;
    char* line = NULL;
    size_t len = 0;

    fileData = fopen(fileLocation, "r");

    // Check if the file exists
    if (fileData == NULL) {
        puts("File not found; exiting");
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fileData)) != -1) {
        struct valueMap valueMapResult;
        valueMapResult.value = atoi(line);
        valueMapResult.line = i;
        i++;
        valueMap[i] = valueMapResult;
    }

    fclose(fileData);
    if (line)
        free(line);
}
