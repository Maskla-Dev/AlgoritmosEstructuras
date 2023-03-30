//
// Created by Montoya Morales Luis Antonio on 24/03/23.
//
#include "HashTables.h"
#include <stdio.h>
#include <stdlib.h>
#include "Base/Arrays/Arrays.h"

int main() {
    IntArray *array = createIntArray(10);
    randomFillIntArray(array, 0, 100);
    char *string = intArrayToString(array, "\t");
    int size = 5;
    printf("%s\n", string);
    free(string);
    IntHashTable *table = sortIntArrayByHash(array, &size, MODULE, LINEAR_PROBING);
    string = intLinkedListArrayToString(table->array, "\n", "\t");
    printf("%s\n", string);
    free(string);
    releaseIntArray(array);
    return 0;
}