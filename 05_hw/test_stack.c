#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_push_null_stack() {
    push(NULL, 10); 
    printf("Test: push with NULL stack - PASSED\n");
}

void test_pop_null_stack() {
    pop(NULL);
    printf("Test: pop with NULL stack - PASSED\n");
}

void test_destroyStack_null_stack() {
    destroyStack(NULL);
    printf("Test: destroyStack with NULL stack - PASSED\n");
}

void test_initStack_null() {
    initStack(NULL); 
    printf("Test: initStack with NULL - PASSED\n");
}

void test_destroyStack_non_empty() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    assert(stack.top == NULL);

    printf("Test: destroyStack on non-empty stack - PASSED\n");
}

void test_getTop_non_empty_stack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    Node* top = getTop(&stack);
    assert(top != NULL && top->data == 20);

    printf("Test: getTop on non-empty stack - PASSED\n");
}

void test_getTop_empty_stack() {
    Stack stack;
    initStack(&stack);

    Node* top = getTop(&stack);
    assert(top == NULL);

    printf("Test: getTop on empty stack - PASSED\n");
}

void test_traverseStack_empty() {
    Stack stack;
    initStack(&stack);

    printf("Expected output: (nothing)\n");
    printf("Actual output: ");
    traverseStack(&stack);

    printf("Test: traverseStack on empty stack - PASSED\n");
}

void test_traverseStack_non_empty() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Expected output: Stack elements: 30 20 10\n");
    printf("Actual output: ");
    traverseStack(&stack);

    printf("Test: traverseStack on non-empty stack - PASSED\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20);

    result = searchByIndex(&stack, 5);
    assert(result == NULL);

    printf("Test: searchByIndex - PASSED\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);

    printf("Test: isEmpty - PASSED\n");
}

void test_searchByValue_null_stack() {
    Node* result = searchByValue(NULL, 10);
    assert(result == NULL); 
    printf("Test: searchByValue with NULL stack - PASSED\n");
}

void test_searchByValue_empty_stack() {
    Stack stack;
    initStack(&stack);

    Node* result = searchByValue(&stack, 10);
    assert(result == NULL); 
    printf("Test: searchByValue on empty stack - PASSED\n");
}

void test_searchByValue_existing_value() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20); 
    printf("Test: searchByValue with existing value - PASSED\n");
}

void test_searchByValue_non_existing_value() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 40);
    assert(result == NULL); 
    printf("Test: searchByValue with non-existing value - PASSED\n");
}


void test_createNode_null() {
    Node* node = createNode(10);
    assert(node != NULL); 
    printf("Test: createNode handles memory allocation successfully - PASSED\n");
}

void test_push_memory_failure() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    assert(stack.top != NULL);
    printf("Test: push handles memory allocation successfully - PASSED\n");
}


void test_searchByIndex_null_stack() {
    Node* result = searchByIndex(NULL, 0);
    assert(result == NULL);
    printf("Test: searchByIndex with NULL stack - PASSED\n");
}


void test_traverseStack_null_stack() {
    traverseStack(NULL); 
    printf("Test: traverseStack with NULL stack - PASSED\n");
}

int main() {

    test_push_null_stack();
    test_pop_null_stack();
    test_destroyStack_null_stack();
    test_initStack_null();

    test_destroyStack_non_empty();
    test_getTop_non_empty_stack();
    test_getTop_empty_stack();
    test_traverseStack_empty();
    test_traverseStack_non_empty();
    test_searchByIndex();
    test_isEmpty();

    test_searchByValue_null_stack();
    test_searchByValue_empty_stack();
    test_searchByValue_existing_value();
    test_searchByValue_non_existing_value();

    test_createNode_null();
    test_push_memory_failure();

    test_searchByIndex_null_stack();
    test_traverseStack_null_stack();

    printf("All tests passed successfully!\n");
    return 0;
}
