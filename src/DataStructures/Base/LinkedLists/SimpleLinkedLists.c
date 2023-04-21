#include "SimpleLinkedLists.h"
#include "math.h"
#include <stdio.h>

SimpleLinkedList *createSimpleLinkedList() {
  SimpleLinkedList *list = (SimpleLinkedList *)malloc(sizeof(SimpleLinkedList));
  list->head = NULL;
  list->current = NULL;
  return list;
}

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtHead(SimpleLinkedList *list, Node *node) {
  if (list == NULL)
    return;
  if (list->head == NULL) {
    list->head = node;
    list->current = node;
  } else {
    node->next = list->head;
    list->head = node;
  }
}

void insertAtFinal(SimpleLinkedList *list, Node *node) {
  if (list == NULL)
    return;
  if (list->head == NULL) {
    insertAtHead(list, node);
  } else {
    goHead(list);
    while (list->current->next != NULL) {
      goNext(list);
    }
    list->current->next = node;
  }
}

void insertSortedInSimpleLinkedList(SimpleLinkedList *list, int data) {
  if (list == NULL)
    return;
  goHead(list);
  while (list->current != NULL) {
    if (list->current->data > data){
      if(list->current == list->head){
        insertAtHead(list, createNode(data));
        return;
      }
      else{
        insertBefore(list, createNode(data), list->current);
        return;
      }
    }
    goNext(list);
  }
  insertAtFinal(list, createNode(data));
}

void insertBefore(SimpleLinkedList *list, Node *node, Node *before) {
  if (list == NULL)
    return;
  if (list->head == NULL)
    return;
  if (list->head == before) {
    insertAtHead(list, node);
    return;
  }
  goHead(list);
  while (list->current != NULL) {
    if (list->current->next == before) {
      node->next = list->current->next;
      list->current->next = node;
      return;
    }
    goNext(list);
  }
}

void goNext(SimpleLinkedList *list) { list->current = list->current->next; }

void goHead(SimpleLinkedList *list) { list->current = list->head; }

char *simpleLinkedListToString(SimpleLinkedList *linked_list, char *separator) {
  if (linked_list == NULL)
    return "Empty list";
  if (linked_list->head == NULL)
    return "Empty list";
  goHead(linked_list);
  char *result = "";
  while (linked_list->current != NULL) {
    result = concat(result, nodeToString(linked_list->current));
    result = concat(result, separator);
    goNext(linked_list);
  }
  return result;
}

char *nodeToString(Node *node) {
  char *temp;
  size_t length = ((node->data != 0) ? (size_t)log10(abs(node->data)) : 0) + 2;
  temp = calloc(length, sizeof(char));
  sprintf(temp, "%d", node->data);
  return temp;
}

char *concat(char *s1, char *s2) {
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}