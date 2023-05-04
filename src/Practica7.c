//
// Created by Montoya Morales Luis Antonio on 24/04/23.
//
#include "DoubleLinkedList.h"
#include "UIHelpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printList(struct Node *start);

int main() {
    struct Node *start = NULL;
    int user_input, value_to_remove, value_to_insert;
    do {
        printf("1. Insertar en lista\n");
        if (start != NULL)
            printf("2. Imprimir lista\n");
        printf("3. Salir\n");
        user_input = (int) getUserChoice(1, 3);
        switch (user_input) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                value_to_insert = (int) getUserChoice(INT_MIN, INT_MAX);
                start = insertInEvenOddList(start, value_to_insert);
                break;
            case 2:
                if (start != NULL)
                    printList(start);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (user_input != 3);
    return EXIT_SUCCESS;
}

void printList(struct Node *start) {
    struct Node *current = start;
    while (current != NULL) {
        printf("%d\t", current->value);
        current = current->next;
    }
    printf("\n");
}