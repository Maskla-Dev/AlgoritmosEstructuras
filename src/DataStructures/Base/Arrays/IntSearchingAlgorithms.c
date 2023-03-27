//
// Created by maskla on 14/03/23.
//

#include "IntSearchingAlgorithms.h"

int sequentialIntSearch(IntArray *array, int value) {
    for (int i = 0; i < array->size; ++i) {
        if (array->array[i] == value) {
            return i;
        }
    }
    return -1;
}

int binaryIntSearch(IntArray *array, int value, int* iterations) {
    if (iterations != NULL) {
        *iterations = 0;
    }
    if (array->size == 0) {
        return -1;
    }
    int low = 0;
    int high = array->size - 1;
    int mid;
    while (low <= high) {
        if (iterations != NULL) {
            *iterations += 1;
        }
        mid = (low + high) / 2;
        if (array->array[mid] == value) {
            return mid;
        } else if (array->array[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}