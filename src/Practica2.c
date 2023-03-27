//
// Created by Montoya Morales Luis Antonio on 9/03/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "Arrays/Arrays.h"
#include "Arrays/Utils.h"
#include "Arrays/IntSortingAlgorithms.h"

int main() {
    IntArray *array1 = createIntArray(10);
    IntArray *array2 = createIntArray(intRandom(3, 5));
    randomFillIntArray(array1, 0, 20);
    randomFillIntArray(array2, 0, 20);
    intBubbleSort(array1, true);
    intBubbleSort(array2, true);
    char *array1String = intArrayToString(array1, "\t");
    char *array2String = intArrayToString(array2, "\t");
    printf("Array 1:\n%s\n", array1String);
    free(array1String);
    printf("Array 2:\n%s\n", array2String);
    free(array2String);
    IntArray *mergedArray = mergeIntArrays(array1, array2, true);
    printf("Done!\n");
    printf("Merged array:\n");
    char *mergedArrayString = intArrayToString(mergedArray, "\t");
    printf("%s\n", mergedArrayString);
    free(mergedArrayString);
    return EXIT_SUCCESS;
}