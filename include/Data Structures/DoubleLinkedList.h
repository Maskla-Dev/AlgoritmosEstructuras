//
// Created by Montoya Morales Luis Antonio on 24/04/23.
//

#ifndef ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
#define ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H

#define isEven(x) (x % 2 == 0)

#include <stdbool.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

typedef enum {
    CURRENT_IS_HEAD,
    CURRENT_IS_TAIL,
    AT_NEXT,
    AT_PREV
} EvenOddListCases;

typedef bool (*DirectiveToContinue)(struct Node *, int, int);

typedef unsigned int (*InsertionCaseSolver)(struct Node *, int);

struct Node *createDLNode(int value);

void insertAtNext(struct Node *node, struct Node *new_node);

void insertAtPrev(struct Node *node, struct Node *new_node);

void insertAtHead(struct Node *node, struct Node *new_node);

void insertAtTail(struct Node *node, struct Node *new_node);

struct Node *removeFromDL(struct Node *start, int value);

struct Node *modifyInEvenOdd(struct Node *start, int value, int new_value);

struct Node *
insertInList(struct Node *start, int value, DirectiveToContinue shouldContinue, InsertionCaseSolver getInsertionCase);

struct Node *insertInEvenOddList(struct Node *list, int value);

bool shouldMoveThroughoutEvenOddList(struct Node *next_node, int current_node_value, int value_to_insert);

unsigned int getInsertionCaseInEvenOddList(struct Node *node, int value);



#endif //ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
