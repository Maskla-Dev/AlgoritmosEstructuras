//
// Created by Montoya Morales Luis Antonio on 29/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_CHARLINKEDLIST_H
#define ALGORITMOSESTRUCTURAS_CHARLINKEDLIST_H

#include "LinkedLists.h"
#include <stdlib.h>

typedef struct StringNode {
    char *data;
    size_t length;
    struct StringNode *next;
} StringNode;

typedef struct {
    StringNode *head;
    StringNode *tail;
    StringNode *current;
} StringLinkedList;

StringLinkedList *createStringLinkedList();

StringNode *intNodeToStringNode(IntNode *node);

#endif //ALGORITMOSESTRUCTURAS_CHARLINKEDLIST_H
