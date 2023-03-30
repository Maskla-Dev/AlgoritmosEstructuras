//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Arrays.h"
#include "Utils.h"

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *) malloc(sizeof(IntArray));
    array->array = (int *) calloc(size, sizeof(int));
    array->size = size;
    return array;
}

IntLinkedListArray *createIntLinkedListArray(int size) {
    IntLinkedListArray *array = (IntLinkedListArray *) malloc(sizeof(IntLinkedListArray));
    array->data = (IntLinkedList *) calloc(size, sizeof(IntLinkedList));
    array->size = size;
    return array;
}

void releaseIntLinkedListArray(IntLinkedListArray *array) {
    for (int i = 0; i < array->size; ++i) {
        clearList(&array->data[i]);
    }
    free(array->data);
    free(array);
}

void releaseIntArray(IntArray *array) {
    free(array->array);
    free(array);
}

void initIntLinkedListArray(IntLinkedListArray *array) {
    for (int i = 0; i < array->size; ++i) {
        array->data[i].head = NULL;
        array->data[i].tail = NULL;
        array->data[i].current = NULL;
    }
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

char *intLinkedListArrayToString(IntLinkedListArray *array, char *array_separator, char *list_separator) {
    char *string = (char *) malloc(sizeof(char));
    string[0] = '\0';
    char *temp, *label;
    for (int i = 0; i < array->size; ++i) {
        label = (char *) calloc(30, sizeof(char));
        sprintf(label, "List %d\n: ", i);
        temp = intLinkedListToString(&array->data[i], list_separator);
        temp = concat(string, label);
        string = concat(string, temp);
        string = concat(string, array_separator);
        free(temp);
    }
    return string;
}