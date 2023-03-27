//
// Created by Montoya Morales Luis Antonio on 13/03/23.
//

#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

int intRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char *intToString(int number) {
    char *string = (char *) calloc(10, sizeof(char));
    sprintf(string, "%d", number);
    return string;
}