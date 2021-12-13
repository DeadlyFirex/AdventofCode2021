#include <stdio.h>

#include "utils.h"

int main() {
    int higher = 0;
    int previous = 0;
    int arr[2001];

    // Read the file, returns integer array
    readFile(arr, "./input/input1.txt");

    puts("Welcome to the Challenge One solver for Advent of Code [2021]!");

    // Loop over the numbers provided by the array
    foreach(int *i, arr) {
        if (previous == 0) {
            previous = arr[1];
        } else {
            if (*i == 0) {
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
