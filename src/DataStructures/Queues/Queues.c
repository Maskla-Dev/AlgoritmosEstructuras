//
// Created by Montoya Morales Luis Antonio 26/03/23.
//
#include "Queues.h"

IntQueue *createIntQueue() {
    IntQueue *queue = (IntQueue *) malloc(sizeof(IntQueue));
    queue->size = 0;
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

void pushBackInIntQueue(IntQueue *queue, int val) {
    Node *node = createNode(val);
    if (queue->size == 0) {
        queue->front = node;
        queue->back = node;
    } else {
        queue->back->next = node;
        queue->back = node;
    }
    queue->size++;
}

Node* popInIntQueue(IntQueue *queue) {
    Node *node;
    if (queue->size == 0) {
        return NULL;
    }
    else if(queue->size == 1){
        node = queue->front;
        queue->front = NULL;
        queue->back = NULL;
        queue->size--;
        return node;
    }
    node = queue->front;
    queue->front = queue->front->next;
    node->next = NULL;
    queue->size--;
    return node;
}

int getFrontInIntQueue(IntQueue *queue) {
    return queue->back->data;
}

unsigned int getIntQueueSize(IntQueue *queue) {
    return queue->size;
}