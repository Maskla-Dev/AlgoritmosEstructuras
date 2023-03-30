//
// Created by maskla on 29/03/23.
//

#include "CharLinkedList.h"
#include <stdlib.h>
#include <math.h>

StringLinkedList *createStringLinkedList() {
    StringLinkedList *list = malloc(sizeof(StringLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

StringNode *intNodeToStringNode(IntNode *node) {
    size_t int_length = (size_t) log10((double) node->data) + 3;
    char *string = (char *) calloc(int_length, sizeof(char));
    StringNode *stringNode = malloc(sizeof(StringNode));
    stringNode->data = string;
    stringNode->length = int_length;
    stringNode->next = NULL;
    return stringNode;
}
