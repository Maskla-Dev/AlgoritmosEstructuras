//
// Created by Montoya Morales Luis Antonio on 26/03/23.
//
#include "HashTables.h"
#include <stdlib.h>
#include "LinkedLists.h"

IntHashTable *createIntHashTable(size_t size, HashFunction hash_function_type, CollisionSolve collision_solve) {
    IntHashTable *hash_table = (IntHashTable *) calloc(1, sizeof(IntHashTable));
    hash_table->hashFunction = hash_function_type;
    hash_table->collisionFunction = collision_solve;
    hash_table->array = createIntLinkedListArray((int) size);
    return hash_table;
}

void insertValueIntHashTable(IntHashTable *hash_table, int value, int middle_size) {
    unsigned int position = getPosition(value, hash_table->array->size, middle_size, hash_table->hashFunction);
    IntNode *node_to_insert = createNode();
    node_to_insert->data = value;
    if (hash_table->array->data[position].current == NULL) {
        hash_table->array->data[position].head = node_to_insert;
        hash_table->array->data[position].tail = node_to_insert;
        hash_table->array->data[position].current = node_to_insert;
    } else {
        switch (hash_table->collisionFunction) {
            default:
            case SEPARATE_CHAINING:
                goTail(&hash_table->array->data[position]);
                insertNext(hash_table->array->data[position].current, node_to_insert);
                break;
        }
    }
}

IntHashTable *
sortIntArrayByHash(IntArray *array, int *fixed_size, HashFunction hash_function_type,
                   CollisionSolve collision_function) {
    IntHashTable *hash_table = createIntHashTable(array->size, hash_function_type,
                                                  collision_function);
    for (int i = 0; i < array->size; ++i) {
        insertValueIntHashTable(hash_table, array->array[i], fixed_size[i]);
    }
    return hash_table;
}

int searchValue(IntHashTable *hashTable, int value) {
    unsigned int position = getPosition(value, hashTable->array->size, 0, hashTable->hashFunction);
    goHead(&hashTable->array->data[position]);
    if (hashTable->array->data[position].current == NULL) {
        return -1;
    } else {
        switch (hashTable->collisionFunction) {
            default:
            case SEPARATE_CHAINING:
                goHead(&hashTable->array->data[position]);
                while (hashTable->array->data[position].current != NULL) {
                    if (hashTable->array->data[position].current->data == value) {
                        return position;
                    }
                    goNext(&hashTable->array->data[position]);
                }
                return -1;
        }
    }
}