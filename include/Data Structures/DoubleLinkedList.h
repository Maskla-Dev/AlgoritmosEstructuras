//
// Created by maskla on 24/04/23.
//

#ifndef ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
#define ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H

#include <stdbool.h>

typedef struct DoubleLinkedNode{
    int value;
    struct DoubleLinkedNode* next;
    struct DoubleLinkedNode* prev;
}DL_IntNode;

typedef struct EvenOddList{
    DL_IntNode* odd_set;
    DL_IntNode* even_set;
} EvenOddList;

typedef enum{
    AT_START = 0b00u,
    AT_END = 0b01u,
    AT_MIDDLE = 0b10u,
} InsertionCases;

DL_IntNode *createDLNode(int value);
EvenOddList *createEvenOddList();
void insertNext(DL_IntNode *node, DL_IntNode *new_node, DL_IntNode *end_mark);
void insertPrev(DL_IntNode *node, DL_IntNode *new_node, DL_IntNode *start_mark);
DL_IntNode* insertInListKeepSort(DL_IntNode *start, int value, bool is_ascendant, DL_IntNode *start_mark, DL_IntNode *end_mark);
void insertInImpairPairList(EvenOddList *list, int value, bool is_ascendant);
bool isCorrectOrder(bool isAscendant, int value1, int value2);
unsigned int getInsertionCase(DL_IntNode* node);

#endif //ALGORITMOSESTRUCTURAS_DOUBLELINKEDLIST_H
