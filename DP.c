#include <stdio.h>
#include <stdlib.h>

extern double dot_product_kernel(int n, double* vec1, double* vec2, double* sdot);

int main() {
    // Example vectors (double precision)
    double vec1[] = {1.0, 2.0, 3.0, 4.0};
    double vec2[] = {0.5, 1.5, 2.5, 3.5};
    double sdot = 0.0; 

    int n = 4;  
    
    //FOR DEBUG:print initial val
    printf("Before calling dot_product_kernel: %f\n", sdot);
    dot_product_kernel(n, vec1, vec2, &sdot);
    //print after calling
    printf("After calling dot_product_kernel: %f\n", sdot);
    // Print ans
    printf("Dot product result: %f\n", sdot);

    return 0;
}
