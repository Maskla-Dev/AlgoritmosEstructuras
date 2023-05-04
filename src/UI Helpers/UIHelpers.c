//
// Created by Montoya Morales Luis Antonio on 14/03/23.
//

#include "UIHelpers.h"
#include <stdio.h>
#include <stdlib.h>

long getUserChoice(int min, int max) {
    char user_input[10];
    long option;
    do {
        fprintf(stdout, "Introduzca su opción (%d-%d): ", min, max);
        scanf("%s", user_input);
        option = strtol(user_input, NULL, 10);
    } while (option < min || option > max);
    return option;
}