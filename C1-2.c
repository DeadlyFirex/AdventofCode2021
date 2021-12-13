#include <stdio.h>

#include "utils.h"

int main() {
    int higher = 0;
    int index = 0;
    int result[1000];
    int initialized = -1;
    struct valueMap valueMap1, valueMap2, valueMap3;
    struct valueMap valueMapList[2000];

    // Read the file, returns integer array
    readFileValueMap(valueMapList, "./input/input1.txt");

    puts("Welcome to the Challenge One (Part 2) solver for Advent of Code [2021]!");

    while (index < 2001) {
        if (initialized == -1) {
            valueMap1 = valueMapList[1];
            valueMap2 = valueMapList[2];
            valueMap3 = valueMapList[3];
            result[0] = valueMap1.value + valueMap2.value + valueMap3.value;
            initialized = 1;
            higher++;
            printf("[INIT] SUM: [%d] FIRST: [%d] - SECOND: [%d] - THIRD: [%d] (%d) \n", result[0], valueMap1.value, valueMap2.value, valueMap3.value, index);
            continue;
        }
        if (BETWEEN(index, 0, 3)) {
            index++;
            continue;
        } else {
            valueMap1 = valueMap2;
            valueMap2 = valueMap3;
            valueMap3 = valueMapList[index];
            result[index] = valueMap1.value + valueMap2.value + valueMap3.value;
            if (result[index] > result[index - 1]) {
                printf("[%d] was higher than [%d]\n", result[index], result[index -1]);
                higher++;
            } else {
                printf("[%d] was not higher than [%d]\n", result[index], result[index -1]);
            }
            index++;
            printf("[RUN] SUM: [%d] FIRST: [%d] - SECOND: [%d] - THIRD: [%d] (%d)\n", result[index], valueMap1.value, valueMap2.value, valueMap3.value, index);
        }
    }

    printf("Result: %d", higher );
    return 0;
}
