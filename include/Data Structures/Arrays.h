//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_ARRAYS_H
#define ALGORITMOSESTRUCTURAS_ARRAYS_H

#include "LinkedLists.h"

typedef struct {
    int *array;
    int size;
} IntArray;

typedef struct IntLinkedListArray{
    IntLinkedList *data;
    int size;
}IntLinkedListArray;

IntArray *createIntArray(int size);

IntLinkedListArray *createIntLinkedListArray(int size);

void releaseIntLinkedListArray(IntLinkedListArray *array);

void releaseIntArray(IntArray *array);

void randomFillIntArray(IntArray *array, int min, int max);

void initIntLinkedListArray(IntLinkedListArray *array);

void copyIntArray(IntArray *src, IntArray *target, int from, int to);

char *intArrayToString(IntArray *array, char *separator);

void swapIntArrays(IntArray *array1, IntArray *array2);

char* intLinkedListArrayToString(IntLinkedListArray *array, char* array_separator,char *list_separator);

#endif //ALGORITMOSESTRUCTURAS_ARRAYS_H
