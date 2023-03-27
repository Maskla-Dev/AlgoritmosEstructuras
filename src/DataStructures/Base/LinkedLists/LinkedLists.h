//
// Created by maskla on 26/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_LINKEDLISTS_H
#define ALGORITMOSESTRUCTURAS_LINKEDLISTS_H

#include <stdbool.h>

typedef struct IntNode {
    int data;
    struct IntNode *next;
    struct IntNode *prev;
} IntNode;

typedef struct {
    IntNode *head;
    IntNode *tail;
    IntNode *current;
} IntLinkedList;

IntLinkedList *createIntLinkedList();

void goNext(IntLinkedList *list);

void goPrev(IntLinkedList *list);

void goHead(IntLinkedList *list);

void goTail(IntLinkedList *list);

IntNode *getTail(IntNode *node);

IntNode *getHead(IntNode *node);

void insertNext(IntNode *node, IntNode *newNode);

void insertPrev(IntNode *node, IntNode *newNode);

IntNode *createNode();

IntNode *searchNode(IntLinkedList *list, int data);

void removeNext(IntNode *node);

void removePrev(IntNode *node);

void clearList(IntLinkedList *list);

#endif //ALGORITMOSESTRUCTURAS_LINKEDLISTS_H
