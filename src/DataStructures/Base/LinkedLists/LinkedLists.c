//
// Created by Montoya Morales Luis Antonio, Trejo Hernandez Brandon on 26/03/23.
//
#include "LinkedLists.h"
#include <stdlib.h>
#include "CharLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

IntLinkedList *createIntLinkedList() {
    IntLinkedList *list = malloc(sizeof(IntLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

void goNext(IntLinkedList *list) {
    if (list->current != NULL) {
        list->current = (IntNode *) list->current->next;
    }
}

void goPrev(IntLinkedList *list) {
    if (list->current != NULL) {
        list->current = (IntNode *) list->current->prev;
    }
}

void goHead(IntLinkedList *list) {
    if (list->head != NULL) {
        list->current = list->head;
    }
}

void goTail(IntLinkedList *list) {
    if (list->tail != NULL) {
        list->current = list->tail;
    }
}

IntNode *getTail(IntNode *node) {
    if (node != NULL) {
        while (node->next != NULL) {
            node = node->next;
        }
    }
    return node;
}

IntNode *getHead(IntNode *node) {
    if (node != NULL) {
        while (node->prev != NULL) {
            node = node->prev;
        }
    }
    return node;
}

void insertNext(IntNode *node, IntNode *newNode) {
    IntNode *temp = (IntNode *) node->next;
    IntNode *new_node_tail;
    if (node != NULL) {
        node->next = newNode;
        newNode->prev = node;
        if (temp != NULL) {
            new_node_tail = getTail(newNode);
            new_node_tail->next = temp;
            temp->prev = new_node_tail;
        }
        node->next = newNode;
    }
}

void insertPrev(IntNode *node, IntNode *newNode) {
    IntNode *temp = (IntNode *) node->prev;
    IntNode *new_node_head;
    if (node != NULL) {
        node->prev = newNode;
        newNode->next = node;
        if (temp != NULL) {
            new_node_head = getHead(newNode);
            new_node_head->prev = temp;
            temp->next = new_node_head;
        }
        node->prev = newNode;
    }
}

IntNode *createNode() {
    IntNode *node = malloc(sizeof(IntNode));
    node->data = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

IntNode *searchNode(IntLinkedList *list, int data) {
    IntNode *node = list->head;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void removeNext(IntNode *node) {
    IntNode *temp = (IntNode *) node->next;
    if (temp != NULL) {
        node->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = node;
        }
        free(temp);
    }
}

void removePrev(IntNode *node) {
    IntNode *temp = (IntNode *) node->prev;
    if (temp != NULL) {
        node->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = node;
        }
        free(temp);
    }
}

void clearList(IntLinkedList *list) {
    IntNode *node = list->head;
    IntNode *temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

char *intLinkedListToString(IntLinkedList *linked_list, char *separator) {
    char *string = malloc(sizeof(char));
    string[0] = '\0';
    char *temp;
    goHead(linked_list);
    while (linked_list->current != NULL) {
        temp = intNodeToString(linked_list->current);
        string = concat(string, temp);
        string = concat(string, separator);
        free(temp);
        goNext(linked_list);
    }
    return string;
}

char *intNodeToString(IntNode *node) {
    char *temp;
    size_t length = (size_t) log10(node->data) + 2;
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