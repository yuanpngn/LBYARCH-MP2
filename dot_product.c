/*PANGAN, YUMI ANN  || DE LOS REYES, CARL JUSTIN*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <immintrin.h>

/*
Algo:
1. Initialize sdot (the result) to 0.0.
2. Loop through vectors A and B from index 0 to n-1:
   - Multiply the corresponding elements A[i] and B[i].
   - Accumulate the product into sdot.
3. Store the final value of sdot.
*/

void dot_product_c(const double* A, const double* B, double* sdot, int n) {
    __m256d sum = _mm256_setzero_pd();
    int i;

    for (i = 0; i <= n - 4; i += 4) {
        __m256d vecA = _mm256_load_pd(A + i);
        __m256d vecB = _mm256_load_pd(B + i);
        __m256d prod = _mm256_mul_pd(vecA, vecB);
        sum = _mm256_add_pd(sum, prod);
    }

    double temp[4];
    _mm256_store_pd(temp, sum);
    *sdot = temp[0] + temp[1] + temp[2] + temp[3];

    for (; i < n; ++i) {
        *sdot += A[i] * B[i];
    }
}

//assembly kernel declaration
extern void dot_product_asm(const double* A, const double* B, double* sdot, int n);

int main() {
    const int sizes[] = {1 << 20, 1 << 24, 1 << 28};
    double *A, *B, sdot_c, sdot_asm;

    for (int test = 0; test < 3; ++test) {
        int n = sizes[test];
        A = (double*)aligned_alloc(32, n * sizeof(double));
        B = (double*)aligned_alloc(32, n * sizeof(double));

        for (int i = 0; i < n; ++i) {
            A[i] = rand() / (double)RAND_MAX;
            B[i] = rand() / (double)RAND_MAX;
        }
        //c kernel timing
        clock_t start_c = clock();
        for (int i = 0; i < 20; ++i) {
            dot_product_c(A, B, &sdot_c, n);
        }
        clock_t end_c = clock();
        printf("C Kernel | Size: %d | Avg Time: %.6f ms | Result: %.6f\n",
               n, (double)(end_c - start_c) / (20 * CLOCKS_PER_SEC) * 1000, sdot_c);

        //assemblyu kernel timing
        clock_t start_asm = clock();
        for (int i = 0; i < 20; ++i) {
            dot_product_asm(A, B, &sdot_asm, n);
        }
        clock_t end_asm = clock();
        printf("ASM Kernel | Size: %d | Avg Time: %.6f ms | Result: %.6f\n",
               n, (double)(end_asm - start_asm) / (20 * CLOCKS_PER_SEC) * 1000, sdot_asm);

        if (fabs(sdot_c - sdot_asm) < 1e-6) {
            printf("Correctness Check: PASSED\n");
        } else {
            printf("Correctness Check: FAILED\n");
        }

        free(A);
        free(B);
    }

    return 0;
}