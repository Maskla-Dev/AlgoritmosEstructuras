//
// Created by maskla on 24/04/23.
//

#ifndef ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
#define ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H

#define isEven(x) (x % 2 == 0)

#include <stdbool.h>

typedef struct DoubleLinkedNode {
    int value;
    struct DoubleLinkedNode *next;
    struct DoubleLinkedNode *prev;
} DL_IntNode;

typedef enum {
    CURRENT_IS_HEAD,
    CURRENT_IS_TAIL,
    AT_NEXT,
    AT_PREV
} EvenOddListCases;

typedef bool (*DirectiveToContinue)(DL_IntNode *, int, int);

typedef unsigned int (*InsertionCaseSolver)(DL_IntNode *, int);

DL_IntNode *createDLNode(int value);

void insertAtNext(DL_IntNode *node, DL_IntNode *new_node);

void insertAtPrev(DL_IntNode *node, DL_IntNode *new_node);

void insertAtHead(DL_IntNode *node, DL_IntNode *new_node);

void insertAtTail(DL_IntNode *node, DL_IntNode *new_node);

DL_IntNode *removeFromDL(DL_IntNode *start, int value);

DL_IntNode *modifyInEvenOdd(DL_IntNode *start, int value, int new_value);

DL_IntNode *
insertInList(DL_IntNode *start, int value, DirectiveToContinue shouldContinue, InsertionCaseSolver getInsertionCase);

DL_IntNode *insertInEvenOddList(DL_IntNode *list, int value);

bool shouldMoveThroughoutEvenOddList(DL_IntNode *next_node, int current_node_value, int value_to_insert);

unsigned int getInsertionCaseInEvenOddList(DL_IntNode *node, int value);



#endif //ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
