#include "SimpleLinkedLists.h"
#include <stdio.h>
#include <stdlib.h>
#include "UIHelpers.h"
#include <limits.h>

void Menu();

int main() {
    Menu();
    return EXIT_SUCCESS;
}

void Menu(){
    int option;
    SimpleLinkedList *list = createSimpleLinkedList();
    char* str;
    do{
        printf("1. Insertar ordenado\n");
        printf("2. Mostrar lista\n");
        printf("3. Salir\n");
        option = getUserChoice(1, 3);
        switch(option){
            case 1:
                printf("Ingrese el dato a insertar: ");
                int data = getUserChoice(INT_MIN, INT_MAX);
                insertSortedInSimpleLinkedList(list, data);
                break;
            case 2:
                str = simpleLinkedListToString(list, "\t");
                printf("Lista: %s\n", str);
                free(str);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
        }
    }while(option != 3);
}