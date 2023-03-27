//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Arrays/Arrays.h"
#include "Arrays/IntSortingAlgorithms.h"
#include "UI Helpers/UIHelpers.h"
#include <time.h>

int main() {
    long user_input = 0;
    char *string = NULL;
    double time_spent = 0.0;
    clock_t begin, end;
    printf("Introduce el tamaño del arreglo: \n");
    user_input = getUserChoice(0, INT_MAX);
    IntArray *array = createIntArray((int) user_input);
    randomFillIntArray(array, 1, 99999);
    printf("Quiere mostrar el arreglo? (1 = Si, 0 = No)\n");
    user_input = getUserChoice(0, 1);
    if (user_input == 1) {
        string = intArrayToString(array, "\t");
        printf("Arreglo: \n");
        printf("%s\n", string);
        free(string);
        string = NULL;
    }
    begin = clock();
    sortIntArray(array, MERGE_SORT, true);
    end = clock();
    printf("Quiere mostrar el arreglo ordenado? (1 = Si, 0 = No): ");
    user_input = getUserChoice(0, 1);
    if (user_input == 1) {
        string = intArrayToString(array, "\t");
        printf("Arreglo ordenado: \n");
        printf("%s\n", string);
        free(string);
        string = NULL;
    }
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos", time_spent);
    return EXIT_SUCCESS;
}