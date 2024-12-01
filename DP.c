// PANGAN, YA || DELOS REYES, CJ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double dot_product_kernel(int n, double* vec1, double* vec2, double* sdot);

// C version => dot product
double dot_product(int n, double* vec1, double* vec2) {
    double result = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

void run_test(int n) {
    double* vec1 = (double*)malloc(n * sizeof(double));
    double* vec2 = (double*)malloc(n * sizeof(double));
    double sdot_asm = 0.0;

    // use random vals
    int i;
    for ( i = 0; i < n; i++) {
        vec1[i] = rand() % 100;
        vec2[i] = rand() % 100;
    }

	// calc d time
    clock_t start_c = clock();
    double result_c = dot_product(n, vec1, vec2);
    clock_t end_c = clock();
    double time_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC * 1000.0; // Time in ms

    clock_t start_asm = clock();
    dot_product_kernel(n, vec1, vec2, &sdot_asm);
    clock_t end_asm = clock();
    double time_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC * 1000.0; // Time in ms

    printf("C Kernel | Size: %d | Avg Time: %.3f ms | Result: %.6f\n", n, time_c, result_c);
    printf("ASM Kernel | Size: %d | Avg Time: %.3f ms | Result: %.6f\n", n, time_asm, sdot_asm);
    
    if (result_c == sdot_asm) {
        printf("Correctness Check: PASSED\n");
    } else {
        printf("Correctness Check: FAILED\n");
    }

    double speedup = time_c / time_asm;
    printf("Speedup: %.2fx\n", speedup);

    free(vec1);
    free(vec2);
}

int main() {
    int i, n;
    for ( i = 20; i <= 28; i++) {
         n = 1 << i;  // n = 2^i
        printf("\nRunning test for vector size 2^%d (%d elements)...\n", i, n);
        run_test(n);
    }

    return 0;
}
