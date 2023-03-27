//
// Created by LAMM_ on 27/03/2023.
//
#include "HashFunctions.h"
#include <math.h>
#include <limits.h>

int module(int key, int size) {
    return abs(key) % size;
}

unsigned int square(int key) {
    return centralDigits(key * key, 2);
}

unsigned int foldSum(int key, unsigned short middle_size) {
    int sum = 0;
    IntArray *array = fold(key, middle_size);
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; i < array->size; ++i) {
        sum += array->array[i];
    }
    return sum;
}

unsigned short digitLength(int value) {
    return ((int) log10(value)) + 1;
}

IntArray *fold(int value, unsigned short fold_size) {
    int length = digitLength(value);
    int iterations;
    IntArray *array;
    if (fold_size == 0 || fold_size > length) {
        return NULL;
    }
    array = createIntArray(length / fold_size);
    value = abs(value);
    iterations = length / fold_size;
    for (int i = 0; i < iterations; ++i) {
        array->array[i] = value % ((int) pow(10, length - fold_size));
        value /= (int) pow(10, length - fold_size);
        length -= fold_size;
    }
    return array;
}

int centralDigits(int value, unsigned short middle_size) {
    int length = digitLength(value);
    int head_cut = 0;
    int tail_cut = 0;
    value = abs(value);
    if (length == middle_size) {
        return value;
    }
    head_cut = (length - middle_size) / 2;
    tail_cut = length - middle_size - head_cut;
    for (int i = 1; i <= head_cut; ++i) {
        value /= 10;
        length -= 1;
    }
    for (int i = 1; i <= tail_cut; ++i) {
        value %= (int) pow(10, length - 1);
        length -= 1;
    }
    return value;
}