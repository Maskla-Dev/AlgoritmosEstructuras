//
// Created by maskla on 29/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_HASHTABLES_H
#define ALGORITMOSESTRUCTURAS_HASHTABLES_H

#include "Arrays.h"
#include <stddef.h>
#include "HashFunctions/HashFunctions.h"

typedef struct IntHashTable {
    IntLinkedListArray *array;
    HashFunction hashFunction;
    CollisionSolve collisionFunction;
} IntHashTable;


IntHashTable *createIntHashTable(size_t size, HashFunction hash_function_type, CollisionSolve collision_function);

void insertValueIntHashTable(IntHashTable *hash_table, int value, int middle_size);

int searchValue(IntHashTable *hashTable, int value);

IntHashTable *sortIntArrayByHash(IntArray *array, int *fixed_size, HashFunction hash_function_type, CollisionSolve collision_function);

#endif //ALGORITMOSESTRUCTURAS_HASHTABLES_H
