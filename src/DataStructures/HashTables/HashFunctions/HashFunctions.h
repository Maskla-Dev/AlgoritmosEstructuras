//
// Created by LAMM_ on 27/03/2023.
//

#ifndef ALGORITMOSESTRUCTURAS_HASHFUNCTIONS_H
#define ALGORITMOSESTRUCTURAS_HASHFUNCTIONS_H

#include "Arrays.h"

typedef enum HashFunction {
    MODULE,
    MIDDLE_SQUARE,
    FOLDING,
} HashFunction;

typedef enum CollisionSolve {
    LINEAR_PROBING,
    QUADRATIC_PROBING,
    SEPARATE_CHAINING,
    REHASHING
} CollisionSolve;

unsigned int getPosition(int key, int table_size, int middle_size,HashFunction hash_function);

unsigned int module(int key, int size);

unsigned int square(int key);

unsigned int foldSum(int key, unsigned short middle_size);

int centralDigits(int value, unsigned short middle_size);

IntArray *fold(int value, unsigned short fold_size);

unsigned short digitLength(int value);

#endif //ALGORITMOSESTRUCTURAS_HASHFUNCTIONS_H
