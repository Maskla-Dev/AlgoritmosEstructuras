//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_ARRAYS_H
#define ALGORITMOSESTRUCTURAS_ARRAYS_H

typedef struct {
    int *array;
    int size;
} IntArray;

IntArray *createIntArray(int size);

void releaseIntArray(IntArray *array);

void randomFillIntArray(IntArray *array, int min, int max);

void copyIntArray(IntArray *src, IntArray *target, int from, int to);

char *intArrayToString(IntArray *array, char *separator);

void swapIntArrays(IntArray *array1, IntArray *array2);

#endif //ALGORITMOSESTRUCTURAS_ARRAYS_H
