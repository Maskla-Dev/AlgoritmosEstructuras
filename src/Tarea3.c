//
// Created by Montoya Morale Luis Antonio on 28/04/23.
//
#include "Queues.h"
#include <stdio.h>

int main(){
    int stock[] = {1,2,3,4}, size= 4;
    IntQueue *queue = createIntQueue();
    for(int i = 0; i < size; i++){
        pushBackInIntQueue(queue, stock[i]);
    }
    for (int i = 0; i < size; i++){
        printf("%d\n", popInIntQueue(queue)->data);
    }
    return 0;
}