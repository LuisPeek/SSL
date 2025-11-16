#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "StackModule.h"

void benchmark(StackModule* s) {
    printf("Arranca el benchmark\n");

    double time_spent_total_push = 0, time_spent_total_pop = 0;
    struct timespec start, end;

    int values[CANTIDADMAX];
    for (int i = 0; i < CANTIDADMAX; i++) {
        values[i] = rand() % 10 + 1; // valores aleatorios entre 1 y 10
    }

    for (int i = 0; i < ITERATIONS; i++) {
        inicializacionStack(s);

        // Benchmark PUSH
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < CANTIDADMAX; j++) {
            Push(s, values[j]);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        double time_push = (end.tv_sec - start.tv_sec) * 1000.0 +
                           (end.tv_nsec - start.tv_nsec) / 10000.0;
        time_spent_total_push += time_push;

        // Benchmark POP
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < CANTIDADMAX; j++) {
            Pop(s);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        double time_pop = (end.tv_sec - start.tv_sec) * 1000.0 +
                          (end.tv_nsec - start.tv_nsec) / 10000.0;
        time_spent_total_pop += time_pop;
    }

    double mean_push = time_spent_total_push / ITERATIONS;
    double mean_pop = time_spent_total_pop / ITERATIONS;

    printf("Resultados del benchmark:\n");
    printf("Iteraciones: %d | Operaciones por iteración: %d\n", ITERATIONS, CANTIDADMAX);
    printf("Tiempo promedio PUSH: %.3f ms\n", mean_push);
    printf("Tiempo promedio POP: %.3f ms\n", mean_pop);
}

int main() {
    StackModule pila;
    inicializacionStack(&pila);
    benchmark(&pila);
    return 0;
}

// TERMINADO