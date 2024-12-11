#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_ITERATIONS 1000000

void benchmark_push(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        push(stack, i);
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Push benchmark: %d iterations took %.5f seconds.\n", NUM_ITERATIONS, elapsed_time);
}

void benchmark_pop(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pop(stack);
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Pop benchmark: %d iterations took %.5f seconds.\n", NUM_ITERATIONS, elapsed_time);
}

int main() {
    Stack stack;
    initStack(&stack);

    benchmark_push(&stack);

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        push(&stack, i);
    }

    benchmark_pop(&stack);

    destroyStack(&stack);

    return 0;
}
