//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#include "IntSortingAlgorithms.h"

void sortIntArray(IntArray *array, SortingAlgorithm algorithm, bool isAscending) {
    IntArray *tmp;
    switch (algorithm) {
        case BUBBLE_SORT:
            intBubbleSort(array, isAscending);
            break;
        case MERGE_SORT:
            tmp = intMergeSort(array, isAscending);
            swapIntArrays(array, tmp);
            releaseIntArray(tmp);
            break;
    }
}

void intBubbleSort(IntArray *array, bool isAscending) {
    for (int i = 0; i < array->size; ++i) {
        for (int j = 0; j < array->size - 1; ++j) {
            if (intSortDelegate(array->array[j], array->array[j + 1], isAscending)) {
                int temp = array->array[j];
                array->array[j] = array->array[j + 1];
                array->array[j + 1] = temp;
            }
        }
    }
}

IntArray *mergeIntArrays(IntArray *array1, IntArray *array2, bool is_ascending_sort) {
    int index1 = 0, index2 = 0, index_merged = 0;
    bool first_up_from_second;
    bool exit_flag = false;
    IntArray *mergedArray = createIntArray(array1->size + array2->size);
    while (!exit_flag) {
        if (index1 == array1->size && index2 == array2->size) {
            exit_flag = true;
            continue;
        }
        if (index1 == array1->size) {
            mergedArray->array[index_merged++] = array2->array[index2++];
            continue;
        }
        if (index2 == array2->size) {
            mergedArray->array[index_merged++] = array1->array[index1++];
            continue;
        }
        first_up_from_second = intSortDelegate(array1->array[index1], array2->array[index2], is_ascending_sort);
        mergedArray->array[index_merged++] = !first_up_from_second ? array1->array[index1++] : array2->array[index2++];
    }
    return mergedArray;
}

IntArray *intMergeSort(IntArray *array, bool is_ascending_sort) {
    if (array->size == 1) {
        return array;
    }
    IntArray *array1 = createIntArray(array->size / 2);
    IntArray *array2 = createIntArray(array->size - array1->size);
    copyIntArray(array, array1, 0, array1->size);
    copyIntArray(array, array2, array1->size, array->size);
    array1 = intMergeSort(array1, is_ascending_sort);
    array2 = intMergeSort(array2, is_ascending_sort);
    IntArray *mergedArray = mergeIntArrays(array1, array2, is_ascending_sort);
    releaseIntArray(array1);
    releaseIntArray(array2);
    return mergedArray;
}

bool intSortDelegate(int value1, int value2, bool is_ascending_sort) {
    return is_ascending_sort ? value1 > value2 : value1 < value2;
}

bool isSortedIntArray(IntArray *array, bool is_ascending_sort) {
    for (int i = 0; i < array->size - 1; ++i) {
        if (intSortDelegate(array->array[i], array->array[i + 1], is_ascending_sort)) {
            return false;
        }
    }
    return true;
}