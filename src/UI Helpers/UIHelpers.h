//
// Created by Montoya Morales Luis Antonio on 14/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_UIHELPERS_H
#define ALGORITMOSESTRUCTURAS_UIHELPERS_H

typedef struct {
    int option_number;
    void (*option_delegate)();
    char *option_name;
    char *option_description;
} Option;

long getUserChoice(int min, int max);
//TODO: Add option selector path from struct table (option number, option delegate, option name, option description)
#endif //ALGORITMOSESTRUCTURAS_UIHELPERS_H