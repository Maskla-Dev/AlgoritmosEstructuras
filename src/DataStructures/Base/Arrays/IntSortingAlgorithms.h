//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_INTSORTINGALGORITHMS_H
#define ALGORITMOSESTRUCTURAS_INTSORTINGALGORITHMS_H

#include <stdbool.h>
#include "Arrays.h"

typedef enum {
    BUBBLE_SORT,
    MERGE_SORT
} SortingAlgorithm;

void sortIntArray(IntArray *array, SortingAlgorithm algorithm, bool is_ascending_sort);

bool intSortDelegate(int value1, int value2, bool is_ascending_sort);

IntArray *mergeIntArrays(IntArray *array1, IntArray *array2, bool is_ascending_sort);

IntArray *intMergeSort(IntArray *array, bool is_ascending_sort);

void intBubbleSort(IntArray *array, bool is_ascending_sort);

bool isSortedIntArray(IntArray *array, bool is_ascending_sort);

#endif //ALGORITMOSESTRUCTURAS_INTSORTINGALGORITHMS_H
