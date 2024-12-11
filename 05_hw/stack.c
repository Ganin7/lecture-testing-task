#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack initialization failed: NULL pointer\n");
        return;
    }
    stack->top = NULL;
}

void destroyStack(Stack* stack) {
    if (stack == NULL) {
        return;
    }
    Node* current = stack->top;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
    stack->top = NULL;
}

void push(Stack* stack, int data) {
    if (stack == NULL) {
        fprintf(stderr, "Push failed: NULL stack pointer\n");
        return;
    }
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return; 
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        return; 
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

Node* searchByValue(Stack* stack, int value) {
    if (stack == NULL) {
        return NULL;
    }
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* searchByIndex(Stack* stack, int index) {
    if (stack == NULL) {
        return NULL;
    }
    Node* current = stack->top;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

Node* getTop(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    return stack->top;
}

void traverseStack(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is not initialized.\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool isEmpty(Stack* stack) {
    return stack == NULL || stack->top == NULL;
}
