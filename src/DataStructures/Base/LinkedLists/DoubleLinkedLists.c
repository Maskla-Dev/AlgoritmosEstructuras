//
// Created by Montoya Morales Luis Antonio on 24/04/23.
//
#include "DoubleLinkedList.h"
#include <stdlib.h>

struct Node *createDLNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return node;
}

void insertAtNext(struct Node *node, struct Node *new_node) {
    if (new_node == NULL)
        return;
    new_node->next = node->next;
    new_node->prev = node;
    node->next->prev = new_node;
    node->next = new_node;
}

void insertAtPrev(struct Node *node, struct Node *new_node) {
    if (new_node == NULL)
        return;
    new_node->prev = node->prev;
    new_node->next = node;
    node->prev->next = new_node;
    node->prev = new_node;
}

void insertAtHead(struct Node *node, struct Node *new_node) {
    if (node->prev != NULL && new_node != NULL)
        return;
    new_node->next = node;
    node->prev = new_node;
}

void insertAtTail(struct Node *node, struct Node *new_node) {
    if (node->next != NULL && new_node != NULL)
        return;
    new_node->prev = node;
    node->next = new_node;
}

struct Node *insertInList(struct Node *start, int value, DirectiveToContinue shouldContinue,
                          InsertionCaseSolver getInsertionCase) {
    struct Node *new_node = createDLNode(value);
    struct Node *current;
    if (start == NULL) {
        return new_node;
    }
    current = start;
    while (shouldContinue(current->next, current->value, value)) {
        current = current->next;
    }
    switch (getInsertionCase(current, value)) {
        case CURRENT_IS_HEAD:
            insertAtHead(current, new_node);
            start = new_node;
            break;
        case CURRENT_IS_TAIL:
            insertAtTail(current, new_node);
            break;
        case AT_NEXT:
            insertAtNext(current, new_node);
            break;
        case AT_PREV:
            insertAtPrev(current, new_node);
            break;
    }
    return start;
}

struct Node *insertInEvenOddList(struct Node *list, int value) {
    return insertInList(list, value, shouldMoveThroughoutEvenOddList, getInsertionCaseInEvenOddList);
}

bool shouldMoveThroughoutEvenOddList(struct Node *next_node, int current_node_value, int value_to_insert) {
    bool is_even_insert_value = isEven(value_to_insert);
    bool is_to_insert_greater = !is_even_insert_value ? (current_node_value > value_to_insert) : (value_to_insert >
                                                                                                 current_node_value);
    bool is_even_current_node_value = isEven(current_node_value);
    return (next_node != NULL) && (((is_even_current_node_value && is_even_insert_value) ||
                                    (!is_even_current_node_value && !is_even_insert_value)) && is_to_insert_greater ||
                                   (is_even_current_node_value && !is_even_insert_value));
}

unsigned int getInsertionCaseInEvenOddList(struct Node *current_node, int value) {
    bool to_insert_is_even = isEven(value);
    bool current_is_even = isEven(current_node->value);
    bool to_insert_is_greater = !to_insert_is_even ? current_node->value > value : value > current_node->value;
    if (current_node->prev == NULL && current_node->next == NULL) {
        if ((to_insert_is_even && current_is_even) || (!to_insert_is_even && !current_is_even)) {
            return to_insert_is_greater ? CURRENT_IS_TAIL : CURRENT_IS_HEAD;
        } else if (to_insert_is_even && !current_is_even) {
            return CURRENT_IS_HEAD;
        } else if (!to_insert_is_even && current_is_even) {
            return CURRENT_IS_TAIL;
        }
    } else {
        if (!to_insert_is_even) {
            //Already odd numbers in the list but even numbers aren't in the list
            if (current_node->next == NULL) {
                if (to_insert_is_greater)
                    return CURRENT_IS_TAIL;
                return AT_PREV;
            }
                //Already even numbers in the list but stops at the start of the list
            else if (current_node->prev == NULL) {
                return CURRENT_IS_HEAD;
            }
                //Already even numbers in the list but stops at the middle of the list
            else {
                return AT_PREV;
            }
        } else {
            //Already odd numbers but stops at the first even number
            if (current_node->prev == NULL) {
                return CURRENT_IS_HEAD;
            }
                //Already odd numbers but stops at the end of the list
            else if (current_node->next == NULL) {
                if(to_insert_is_greater)
                    return AT_PREV;
                return CURRENT_IS_TAIL;
            }
                //Already odd numbers but stops at the middle of the list
            else {
                //Already odd and even numbers in the list but stops at the end of the odd numbers
                return AT_PREV;
            }
        }
    }
}

struct Node *removeFromDL(struct Node *start, int value) {
    if (start == NULL)
        return start;
    struct Node *current = start;
    while (current->next != NULL) {
        if (current->value == value) {
            if (current->prev == NULL) {
                current->next->prev = NULL;
                start = current->next;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return start;
        }
    }
    return start;
}

struct Node *modifyInEvenOdd(struct Node *start, int value, int new_value) {
    start = removeFromDL(start, value);
    start = insertInEvenOddList(start, new_value);
    return start;
}