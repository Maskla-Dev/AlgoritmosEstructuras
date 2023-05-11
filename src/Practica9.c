//
// Created by maskla on 8/05/23.
//
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

struct Stack *createStack();

struct Node *createNode(int data);

void addToStack(struct Stack *stack, int data);

int removeTop(struct Stack *stack);

long getUserChoice(int min, int max);

int viewTop(struct Stack *stack);

int main() {
    struct Stack *stack = createStack();
    int user_choice, value;
    do{
        printf("1. Agregar a la pila\n");
        if (stack->top != NULL){
            printf("2. Sacar de la pila\n");
            printf("3. Mostrar el tope de la pila\n");
        }
        printf("4. Salir\n");
        user_choice = (int)getUserChoice(1, 4);
        switch (user_choice)
        {
            case 1:
                printf("Introduzca el valor a agregar: ");
                value = (int)getUserChoice(INT_MIN, INT_MAX);
                addToStack(stack, value);
                printf("\n\nEl valor %d ha sido agregado a la pila\n\n", value);
                break;
            case 2:
                if (stack->top != NULL) {
                    printf("\n\nEl valor %d ha sido sacado de la pila\n\n", removeTop(stack));
                }
                break;
            case 3:
                if (stack->top != NULL) {
                    printf("\n\nEl tope de la pila es: %d\n\n", viewTop(stack));
                }
                break;
            case 4:
                printf("\n\nSaliendo...\n\n");
                break;
            default:
                printf("\n\nOpción no válida\n\n");
                break;
        }
    } while (user_choice != 4);
    return EXIT_SUCCESS;
}

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

struct Node *createNode(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addToStack(struct Stack *stack, int data) {
    if (stack == NULL) return;
    struct Node *node = createNode(data);
    node->next = stack->top;
    stack->top = node;
}

int removeTop(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return INT_MAX;
    struct Node *node = stack->top;
    stack->top = stack->top->next;
    int data = node->data;
    free(node);
    return data;
}

int viewTop(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return INT_MAX;
    return stack->top->data;
}

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