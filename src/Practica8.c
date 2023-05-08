//
// Created by Montoya Morale Luis Antonio on 28/04/23.
//
#include <stdio.h>
#include <stdlib.h>

//Simple Linked Lists
typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* createNode(int data);
//Queues
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
//UI Helpers
long getUserChoice(int min, int max);

int main(){
    IntQueue *queue = createIntQueue();
    int user_choice, value;
    do
    {
        printf("1. Agregar a la cola\n");
        if (getIntQueueSize(queue) > 0){
            printf("2. Sacar de la cola\n");
            printf("3. Mostrar el frente de la cola\n");
        }
        printf("4. Salir\n");
        user_choice = getUserChoice(1, 4);
        switch (user_choice)
        {
            case 1:
                printf("Introduzca el valor a agregar: ");
                scanf("%d", &value);
                pushBackInIntQueue(queue, value);
                printf("\n\nEl valor %d ha sido agregado a la cola\n\n", value);
                break;
            case 2:
                if (getIntQueueSize(queue) != 0) {
                    printf("\n\nEl valor %d ha sido sacado de la cola\n\n", popInIntQueue(queue)->data);
                }
                break;
            case 3:
                if (getIntQueueSize(queue) != 0) {
                    printf("\n\nEl frente de la cola es: %d\n\n", getFrontInIntQueue(queue));
                }
                break;
            case 4:
                printf("\n\nSaliendo...\n\n");
                break;
        }
    } while (user_choice != 4);
    
    return 0;
}

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
    return queue->front->data;
}

unsigned int getIntQueueSize(IntQueue *queue) {
    return queue->size;
}

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

long getUserChoice(int min, int max) {
    char user_input[10];
    long option;
    do {
        fprintf(stdout, "Introduzca su opción (%d-%d): ", min, max);
        scanf("%s", user_input);
        option = strtol(user_input, NULL, 10);
    } while (option < min || option > max);
    return option;
}