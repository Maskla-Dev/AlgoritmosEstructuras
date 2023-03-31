//
// Created by Montoya Morales Luis Antonio, Trejo Hernandez Brandon on 24/03/23.
//
#include "HashTables.h"
#include <stdio.h>
#include <stdlib.h>
#include "Base/Arrays/Arrays.h"
#include "UI Helpers/UIHelpers.h"
#include <limits.h>

int main() {
    printf("Indique el tamaño del arreglo: ");
    int size = getUserChoice(1, INT_MAX);
    printf("Tamaño del arreglo: %d\n", size);
    IntArray *array = createIntArray(size);
    for(int i = 0; i < size; i++){
        printf("Indique el valor %d: ", i);
        array->array[i] = getUserChoice(0, INT_MAX);
    }
    char *string = intArrayToString(array, "\t");
    size = 5;
    printf("%s\n", string);
    free(string);
    IntHashTable *table = sortIntArrayByHash(array, &size, MODULE, LINEAR_PROBING);
    string = intLinkedListArrayToString(table->array, "\n", "\t");
    printf("%s\n", string);
    free(string);
    releaseIntArray(array);
    printf("Indique el numero a buscar: ");
    int number = getUserChoice(0, INT_MAX);
    number = searchValue(table, number);
    if(number == -1){
        printf("El numero no se encontro en el arreglo.\n");
    }
    else{
        printf("El numero se encontro en la lista con posicion %d del arreglo.\n", number);
    }
    return 0;
}