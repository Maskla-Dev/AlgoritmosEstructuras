//
// Created by maskla on 28/04/23.
//

#ifndef ALGORITMOSESTRUCTURAS_QUEUES_H
#define ALGORITMOSESTRUCTURAS_QUEUES_H

#include "SimpleLinkedLists.h"

typedef struct {
    unsigned int size;
    Node *front;
    Node *back;
} IntQueue;

Node* popInIntQueue(IntQueue *queue);
void pushBackInIntQueue(IntQueue *queue, int val);
IntQueue* createIntQueue();
int getFrontInIntQueue(IntQueue *queue);
unsigned int getIntQueueSize(IntQueue *queue);

#endif //ALGORITMOSESTRUCTURAS_QUEUES_H
