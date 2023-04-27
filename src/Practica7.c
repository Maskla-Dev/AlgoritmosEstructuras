//
// Created by maskla on 24/04/23.
//
#include "DoubleLinkedList.h"
#include "UIHelpers.h"
#include <stdlib.h>
#include <stdio.h>

void printList(DL_IntNode *start);

int main() {
    int vars[] = {1, 2, 4, 8, 6, -6, -1, 0, -5, -8};
    DL_IntNode *start = NULL;
    for (int i = 0; i < 10; ++i) {
        start = insertInEvenOddList(start, vars[i]);
    }
    printList(start);
//    DL_IntNode *start = NULL;
//    int user_input, value_to_remove, value_to_insert;
//    do {
//        printf("1. Insertar en lista\n2. Imprimir lista\n3. Eliminar\n4. Modificar\n5. Salir\n");
//        user_input = getUserChoice(1, 5);
//        switch (user_input) {
//            case 1:
//                printf("Ingrese el valor a insertar: ");
//                value_to_insert = getUserChoice(INT_MIN, INT_MAX);
//                start = insertInEvenOddList(start, value_to_insert);
//                break;
//            case 2:
//                printList(start);
//                break;
//            case 3:
//                printf("Ingrese el valor a eliminar: ");
//                value_to_remove = getUserChoice(INT_MIN, INT_MAX);
//                start = removeFromDL(start, value_to_remove);
//                break;
//            case 4:
//                printf("Ingrese el valor a modificar: ");
//                value_to_insert = getUserChoice(INT_MIN, INT_MAX);
//                printf("Ingrese el valor a insertar: ");
//                value_to_remove = getUserChoice(INT_MIN, INT_MAX);
//                start = modifyInEvenOdd(start, value_to_remove, value_to_insert);
//                break;
//            case 5:
//                printf("Saliendo...\n");
//                break;
//        }
//    } while (user_input != 5);
//    return EXIT_SUCCESS;
}

void printList(DL_IntNode *start) {
    DL_IntNode *current = start;
    while (current != NULL) {
        printf("%d\t", current->value);
        current = current->next;
    }
    printf("\n");
}