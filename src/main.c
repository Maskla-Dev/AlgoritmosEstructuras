//Autor: Montoya Morales Luis Antonio
#include <stdio.h>
#include "Main.h"
#include <stdlib.h>

int main() {
    MainMenu();
    return 0;
}

void MainMenu(){
    int option, size;
    int *array;
    char user_input[10];
    printf("ESCOM - IPN: Bubble Sort por Luis Antonio Montoya Morales\n");
    size = getUserNumber();
    array = createIntArray(size);
    fillArray(array, size);
    printf("Arreglo original: ");
    printArray(array, size);
    do{
        printf("Seleccione una opción:\n");
        printf("1. Ordenar de forma ascendente\n");
        printf("2. Ordenar de forma descendente\n");
        printf("3. Salir\n");
        scanf("%s", user_input);
        option = (int)strtol(user_input, NULL, 10);
        switch(option){
            case 1:
                bubbleSort(array, size, ASCENDING);
                printf("Arreglo ordenado de forma ascendente: \n");
                printArray(array, size);
                break;
            case 2:
                bubbleSort(array, size, DESCENDING);
                printf("Arreglo ordenado de forma descendente: \n");
                printArray(array, size);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
        printf("\n");
    }while(option != 3);
}

int* createIntArray(int size){
    int *array = (int*)malloc(size * sizeof(int));
    return array;
}

void fillArray(int *array, int size){
    for (int i = 0; i < size; ++i) {
        array[i] = RandomInt(1, 20);
    }
}

int RandomInt(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void printArray(int* array, int size){
    printf("Tamaño del arreglo %d: ", size);
    for (int i = 0; i < size; ++i) {
        printf("\t%d", array[i]);
    }
    printf("\n");
}

int getUserNumber(){
    int number;
    char user_input[10];
    do{
        printf("Introduzca el tamaño del arreglo (Tamaño del 1 al 30):\n");
        scanf("%s", user_input);
        number = (int)strtol(user_input, NULL, 10);
    }while(number < 1 || number > 30);
    return number;
}

void bubbleSort(int *array, int size, SortOptions option) {
    int aux;
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (sortDelegate(array[j], array[j + 1], option)) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

bool sortDelegate(int value1, int value2, SortOptions option){
    return (option == ASCENDING) ? (value1 > value2) : (value1 < value2);
}

