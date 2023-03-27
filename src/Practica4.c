//
// Created by Montoya Morales Luis Antonio on 23/03/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "Arrays.h"
#include "UI Helpers/UIHelpers.h"
#include "IntSortingAlgorithms.h"
#include "IntSearchingAlgorithms.h"

int main() {
    printf("Introduce el tamaño del arreglo: \n");
    long user_input = getUserChoice(0, INT_MAX);
    IntArray *array = createIntArray((int) user_input);
    randomFillIntArray(array, 1, 99999);
    sortIntArray(array, MERGE_SORT, true);
    printf("Quiere mostrar el arreglo? (1 = Si, 0 = No)\n");
    user_input = getUserChoice(0, 1);
    if (user_input == 1) {
        char *string = intArrayToString(array, "\t");
        printf("Arreglo: \n");
        printf("%s\n", string);
        free(string);
        string = NULL;
    }
    printf("Introduzca el número a buscar: \n");
    user_input = getUserChoice(0, INT_MAX);
    int number = (int) user_input;
    int iterations = 0;
    int index = binaryIntSearch(array, number, &iterations);
    if (index == -1) {
        printf("El número no se encontró en el arreglo.\n");
    } else {
        printf("El número se encontró en la posición %d del arreglo.\n", index);
    }
    printf("Número de iteraciones: %d\n", iterations);
    printf("Complejidad del algoritmo empleado: O(log(n))=%.2f\n", log2(array->size));
    return 0;
}