//
// Created by maskla on 2/03/23.
//

#ifndef ALGORITMOSESTRUCTURAS_MAIN_H
#define ALGORITMOSESTRUCTURAS_MAIN_H
#include <stdbool.h>
typedef enum { ASCENDING, DESCENDING } SortOptions;

void bubbleSort(int *array, int size, SortOptions option);
bool sortDelegate(int value1, int value2, SortOptions option);
void printArray(int *array, int size);
int* createIntArray(int size);
void fillArray(int *array, int size);
int RandomInt(int min, int max);

int getUserNumber();
void MainMenu();

#endif //ALGORITMOSESTRUCTURAS_MAIN_H
