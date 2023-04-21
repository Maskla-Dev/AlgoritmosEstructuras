#ifndef ALGORITMOSESTRUCTURAS_SIMPLELINKEDLISTS_H
#define ALGORITMOSESTRUCTURAS_SIMPLELINKEDLISTS_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *current;
} SimpleLinkedList;

SimpleLinkedList* createSimpleLinkedList();
Node* createNode(int data);

void insertAtHead(SimpleLinkedList *list, Node *node);
void insertAtFinal(SimpleLinkedList *list, Node *node);
void insertBefore(SimpleLinkedList *list, Node *node, Node *before);
void clearList(SimpleLinkedList *list);
void goNext(SimpleLinkedList *list);
void goHead(SimpleLinkedList *list);
void insertSortedInSimpleLinkedList(SimpleLinkedList *list, int data);

char* simpleLinkedListToString(SimpleLinkedList* linked_list, char* separator);
char* nodeToString(Node* node);
char *concat(char *string1, char *string2);
#endif //ALGORITMOSESTRUCTURAS_SIMPLELINKEDLISTS_H