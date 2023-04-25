//
// Created by maskla on 24/04/23.
//
#include "DoubleLinkedList.h"
#include <stdlib.h>

DL_IntNode *createDLNode(int value) {
    DL_IntNode *node = (DL_IntNode *) malloc(sizeof(DL_IntNode));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return node;
}

EvenOddList *createEvenOddList() {
    EvenOddList *list = (EvenOddList *) malloc(sizeof(EvenOddList));
    list->odd_set = NULL;
    list->even_set = NULL;
    return list;
}

void insertNext(DL_IntNode *node, DL_IntNode *new_node, DL_IntNode *end_mark) {
    new_node->next = ((node->next == end_mark) ? NULL : node->next);
    new_node->prev = node;
    node->next = new_node;
}

void insertPrev(DL_IntNode *node, DL_IntNode *new_node, DL_IntNode *start_mark) {
    new_node->next = node;
    new_node->prev = ((node->prev == start_mark) ? NULL : node->prev);
    node->prev = new_node;
}

DL_IntNode *insertInListKeepSort(DL_IntNode *start, int value, bool is_ascendant, DL_IntNode *start_mark, DL_IntNode *end_mark) {
    DL_IntNode *new_node = createDLNode(value);
    DL_IntNode *current;
    if (start == NULL) {
        return new_node;
    }
    current = start;
    while(current->next != end_mark){
        if(isCorrectOrder(is_ascendant, current->value, value)) break;
        current = current->next;
    }
    switch (getInsertionCase(current)) {
        case AT_START:
        case AT_MIDDLE:
            is_ascendant ? insertPrev(current, new_node, start_mark) : insertNext(current, new_node, end_mark);
            return new_node;
        case AT_END:
            is_ascendant ? insertNext(current, new_node, end_mark) : insertPrev(current, new_node, start_mark);

            return start;
        default:
            return NULL;
    }
}

/**
 * Single linked list, contains 2 sets of nodes, one for even numbers and one for odd numbers.
 * Insertion cases are:
 * 1. Both sets are empty
 * 2. Odd set is empty
 * 3. Even set is empty
 * 4. Both sets are not empty
 * Solution cases:
 *
 *
 */
void insertInImpairPairList(EvenOddList *list, int value, bool is_ascendant){
    if((value % 2) == 0){
        if(list->even_set == NULL){
            list->even_set = createDLNode(value);
            return;
        }
        if(list->even_set->prev != NULL)
            list->even_set->prev = insertInListKeepSort(list->even_set, value, is_ascendant, (list->even_set->prev == NULL) ? NULL : list->even_set->prev, NULL);
        return;
    }
    if(list->odd_set == NULL){
        list->odd_set = createDLNode(value);
        return;
    }
    list->odd_set = insertInListKeepSort(list->odd_set, value, is_ascendant, NULL, list->even_set);
    list->even_set->prev = (list->even_set->prev == NULL) ? list->odd_set : list->even_set->prev;
}

bool isCorrectOrder(bool isAscendant, int value1, int value2) {
    return ((value1 > value2) & isAscendant) | ((value1 < value2) & !isAscendant);
}

unsigned int getInsertionCase(DL_IntNode *node) {
    return (node->prev == NULL) | ((node->next == NULL) << 1u) | ((node->prev != NULL) & (node->next != NULL) << 2u);
}