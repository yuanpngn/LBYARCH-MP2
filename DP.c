#include <stdio.h>
#include <stdlib.h>

extern double dot_product_kernel(int n, double* vec1, double* vec2, double* sdot);


//for accuracy check
double dot_product(int n, double* vec1, double* vec2) {
    double result = 0.0;
    int i;
    
    for (i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    
    return result;
}

int main() {
    // Example vectors (double precision)
    double vec1[] = {1.0, 2.0, 3.0, 4.0};
    double vec2[] = {0.5, 1.5, 2.5, 3.5};
//	double vec2[] = {1.0, 2.0, 3.0, 4.0, 5};
    double sdot = 0.0; 

    int n = 4;  
    double result = dot_product(n, vec1, vec2);
    //FOR DEBUG:print initial val
    printf("Before calling dot_product_kernel: %f\n", sdot);
    dot_product_kernel(n, vec1, vec2, &sdot);
    //print after calling
    printf("After calling dot_product_kernel (Assembly Code): %f\n", sdot);
    printf("Dot product (C function): %f\n", result);
    
    //checking
    if (sdot == result) {
        printf("The dot product results match!\n");
    } else {
        printf("The dot product results do not match.\n");
    }

    return 0;
}
