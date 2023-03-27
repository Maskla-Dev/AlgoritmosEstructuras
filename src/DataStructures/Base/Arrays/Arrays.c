//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#include <stdlib.h>
#include <string.h>
#include "Arrays.h"
#include "Utils.h"

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *) malloc(sizeof(IntArray));
    array->array = (int *) calloc(size, sizeof(int));
    array->size = size;
    return array;
}

void releaseIntArray(IntArray *array) {
    free(array->array);
    free(array);
}

void randomFillIntArray(IntArray *array, int min, int max) {
    for (int i = 0; i < array->size; ++i) {
        array->array[i] = intRandom(min, max);
    }
}

void copyIntArray(IntArray *src, IntArray *target, int from, int to) {
    if (to <= src->size) {
        for (int i = from; i < to; ++i) {
            target->array[i % target->size] = src->array[i];
        }
    }
}

char *intArrayToString(IntArray *array, char *separator) {
    // 11 is the maximum number of characters that an integer can have, 10 digits and a sign plus a separator
    char *string = (char *) calloc(array->size * (10 + strlen(separator)), sizeof(char));
    for (int i = 0; i < array->size; ++i) {
        char *temp = intToString(array->array[i]);
        strcat(string, temp);
        strcat(string, separator);
        free(temp);
    }
    return string;
}

void swapIntArrays(IntArray *array1, IntArray *array2) {
    int *tmp_ptr = array1->array;
    int tmp_size = array1->size;
    array1->array = array2->array;
    array1->size = array2->size;
    array2->array = tmp_ptr;
    array2->size = tmp_size;
}