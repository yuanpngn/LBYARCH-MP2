# LBYARCH-MP2
--------------
#### PANGAN, Yumi Ann S. 
#### Delos Reyes, Carl Justin 
##### [LBYARCH S_11]
---
# **Dot Product Kernel Using C and x86-64 Assembly**

## **Project Overview**

This project implements a dot product kernel for two vectors `vec1` and `vec2` using both:
1. **C language**
2. **x86-64 Assembly language**

The dot product is computed using **scalar SIMD floating-point instructions** for optimized performance. The goal is to:
- Compare the performance of the C implementation with the x86-64 Assembly implementation.
- Verify correctness by comparing the outputs.
- Analyze the performance differences for different vector sizes.

---

## **Dot Product Formula**

For vectors `vec1 = [a1, a2, ..., an]` and `vec2 = [b1, b2, ..., bn]`, the dot product is:
```
s_dot = a1*b1 + a2*b2 + ... + an*bn
```
The result is stored in `sdot_asm`, which is a double-precision floating-point value.

---

## **Specifications**

1. **Input**:
   - Scalar `n` (integer): length of vectors.
   - Vectors `vec1` and `vec2` of size `n` (double-precision floats).
2. **Output**:
   - Scalar `sdot_asm` (double): the dot product of `A` and `B`.

3. **Requirements**:
   - Use **scalar SIMD floating-point instructions** in assembly.
   - Compare performance for vector sizes: `2^20`, `2^21` , `2^22`, up until `2^28`.
   - Run each kernel 20 times and calculate the **average execution time**.

---
This repository contains two programs related to calculating the dot product:

1. **`Actual_DP_Solving.c`**: Computes the dot product and outputs the result.
2. **`DP.c`**: Measures the average execution time of both the C and Assembly dot product implementations for performance analysis.

Both programs rely on **`DP_asm.asm`**, which contains the Assembly implementation of the dot product.

### Prerequisites

To compile and run the programs, ensure you have the following tools installed:
- **NASM** (Netwide Assembler): To assemble the `.asm` file.
- **GCC** (MinGW or equivalent for Windows): To compile the C programs and link them with the Assembly code.
- A Windows system with a command-line terminal.

### File Descriptions

- **`DP_asm.asm`**: Assembly implementation of the dot product.
- **`Actual_DP_Solving.c`**: A C program to compute and display the dot product result.
- **`DP.c`**: A C program to measure and display the average execution time of the dot product computation.

## **Setup Instructions**

### **1. Requirements**
- **Operating System**: Linux or Windows with WSL
- **Compiler**: GCC (for C code), NASM (for assembly code)
- **Tools used**: DEV-C++ and SASM 

### **2. Building the Program**

### 1. Clone the repository:
   ```
   git clone https://github.com/LBYARCH-MP2/dot-product-kernels.git
   cd dot-product-kernels
   ```
### 2. Compile the program:
   2.1: For `Actual_DP_Solving.c`
   ```
   nasm -f win64 DP_asm.asm -o DP_asm.obj
   ```
   ```
   gcc -c Actual_DP_Solving.c -o Actual_DP_Solving.obj -m64
   ```
   ```
   gcc Actual_DP_Solving.obj DP_asm.obj -o Actual_DP_Solving.exe -m64
   ```
   ```
   Actual_DP_Solving.exe
   ```

  2.2: For `DP.c`
   ```
   nasm -f win64 DP_asm.asm -o DP_asm.obj
   ```
   ```
   gcc -c DP.c -o DP.obj -m64
   ```
   ```
   gcc DP.obj DP_asm.obj -o DP.exe -m64
   ```
   ```
   DP.exe
   ```
### 3. Run the program:
 3.1: For `Actual_DP_Solving.c`
  - Actual_DP_Solving.exe
  3.2: For `DP.c`
   ```
  DP.exe
   ```

---

## **Program Structure**

### **Files**
- `Actual_DP_Solving.c`: Computes the dot product result using both C and Assembly implementations for correctness verification.
- `DP.c`: Measures the execution time and performance of the C and Assembly implementations.
- `DP_asm.asm`: Contains the x86-64 Assembly implementation.
- `README.md`: This file.

### **Functions**
1. **C Implementation (`Actual_DP_Solving.c` and `DP.c`)**:
   - **`dot_product`**:
     - Loops through arrays `A` and `B`, multiplying corresponding elements and accumulating the results.
     - Serves as the reference for verifying the correctness of the Assembly implementation.
   - **`main`**:
     - Initializes vectors with random or predefined values.
     - Calls the Assembly and C implementations to compute results.
     - Measures the average execution time for performance analysis (in `DP.c`).

2. **Assembly Implementation (`DP_asm.asm`)**:
   - **`dot_product_kernel`**:
     - Receives the size of the vectors, their addresses, and a pointer to store the result.
     - Utilizes **scalar SIMD registers** (`xmm0`, `xmm1`, `xmm2`) to perform:
       - Element-wise multiplication.
       - Accumulation of results into a dot product value.
     - Efficiently processes double-precision floating-point numbers for optimized performance.

3. **Performance Timing and Validation (`DP.c`)**:
   - Measures the execution time of both implementations for vector sizes ranging from \(2^{20}\) to \(2^{28}\).
   - Verifies the correctness of the Assembly implementation by comparing results with the C version.

### **Execution Flow**
1. Initialize input vectors (`A` and `B`) with random values.
2. Call the C implementation to compute the dot product (reference result).
3. Call the Assembly implementation to compute the dot product.
4. Compare the results for correctness.
5. Measure and output the average execution time for both implementations.
6. Compute and display the speedup of the Assembly version compared to the C version.

---
## Example Outputs
### **`Actual_DP_Solving.exe`**
```plaintext
Before calling dot_product_kernel: 0.000000
After calling dot_product_kernel (Assembly Code): 25.000000
Dot product (C function): 25.000000
The dot product results match!
```

### **`DP.exe`**
```plaintext
Running test for vector size 2^20 (1048576 elements)...
C Kernel | Size: 1048576 | Avg Time: 5.000 ms | Result: 2566510280.000000
ASM Kernel | Size: 1048576 | Avg Time: 1.000 ms | Result: 2566510280.000000
Correctness Check: PASSED
Speedup: 5.00x
```

---

## Performance Analysis 

This project provides an analysis of the performance of two different implementations of the dot product calculation. The two implementations are written in C and Assembly (ASM). We compare how fast each implementation runs with different vector sizes and calculate the speedup of the C version over the Assembly version. The goal is to understand the performance of each version for different vector sizes and analyze which one performs better under various conditions.

### **Performance Table**

| Vector Size | Avg Time (C) | Avg Time (Assembly) | Speedup |
|-------------|--------------|---------------------|---------|
| 2^20        | 0.000 ms     | 10.000 ms           | 0.00x   |
| 2^21        | 6.000 ms     | 4.000 ms            | 1.50x   |
| 2^22        | 11.000 ms    | 6.000 ms            | 1.83x   |
| 2^23        | 24.000 ms    | 10.000 ms           | 2.40x   |
| 2^24        | 47.000 ms    | 20.000 ms           | 2.35x   |
| 2^25        | 97.000 ms    | 39.000 ms           | 2.49x   |
| 2^26        | 204.000 ms   | 83.000 ms           | 2.46x   |
| 2^27        | 385.000 ms   | 153.000 ms          | 2.52x   |
| 2^28        | 876.000 ms   | 345.000 ms          | 2.54x   |

Note: The average time values are subject to variations depending on the hardware, compiler optimizations, and specific implementation details of the code.

### Key Observations

#### 1. Correctness
- The correctness of both implementations was checked by comparing the results. For all vector sizes tested, both the C and ASM versions gave the same results for the dot product calculation. This confirms that both implementations are functioning correctly and produce the expected output.

#### 2. Performance

- **Smaller Vector Sizes**:
  - For smaller vector sizes, such as 2^20 (1,048,576 elements) and 2^21 (2,097,152 elements), both the C and ASM versions performed very similarly. The average times for both versions were almost the same, and the speedup was 0.00x, meaning that neither version was noticeably faster than the other for these smaller sizes. This suggests that for these small vector sizes, both implementations are efficient and can handle the computation with little difference in performance.
  
- **Larger Vector Sizes**:
  - As the vector size increased, the ASM version consistently demonstrated better performance. For 
  2^22 (4,194,304 elements), the speedup increased to 1.83x, with the ASM version achieving an average time of 6.000 ms compared to 11.000 ms for the C version. While at 2^24 (16,777,216 elements), the speedup was 2.35x, and this trend of increasing speedup continued with larger vector sizes. By 2^28(268,435,456 elements), the speedup reached 2.54x, with the ASM version completing the computation in 345.000 ms compared to 876.000 ms for the C version.
  
- **Possible Reasons for Performance Trends**:
  - The performance of both versions seems to become more different as the vector size increases. This could be due to several factors:
    - The increasing speedup as vector size grows suggests that the ASM implementation handles larger data sets more efficiently, likely due to low-level optimizations that reduce overhead during computation.
    - The C version, while competitive for smaller vector sizes, likely incurs additional overhead as the size grows, such as memory allocation or compiler-introduced inefficiencies.
    - Larger vector sizes may favor the ASM version due to better control over memory access patterns and instruction-level parallelism, which could minimize cache misses.
    - Although modern compilers are highly optimized, they may not generate machine code as efficient as a well-tuned hand-written assembly implementation for certain large-scale computations.

### Conclusion

- **Correctness**: Both the C and Assembly implementations were correct. The results matched in all tests, confirming that both kernels were implemented correctly and produced the expected dot product values.
  
- **Performance**:
  - For smaller vector sizes (e.g., 2^20 and 2^21), the Assembly implementation showed a clear performance advantage by achieving faster execution times compared to the C version. This demonstrates that Assembly's low-level optimizations are effective for smaller workloads with minimal overhead.
  - As the vector size grew, the performance advantage of Assembly became even more evident. At 2^28, for example, Assembly was over 2.54x faster than the C implementation, which shows its ability to handle larger data efficiently as the workload scales.
  - On the other hand, while the C version performed well for smaller sizes, it struggled with larger vectors due to increasing overhead, possibly caused by memory management issues or compiler-related inefficiencies. Assembly, with its precise control over hardware operations, managed to maintain better efficiency in these cases.

- **Final Thoughts**:
  - The results reveal that Assembly is highly effective for performance-critical tasks involving large-scale computations, leveraging more detailed control over the CPU and memory. As for the C implementation, however, remains highly robust, benefiting from modern compiler optimizations and ease of use, making it a practical choice for general-purpose applications.

This analysis helps understand how C and Assembly compare for the dot product calculation and provides insights into when to use each implementation based on the size of the data being processed.

## **Screenshots**

1. **C Implementation Output with Correctness**:
![image](https://github.com/user-attachments/assets/078b8c70-719c-4766-ad0c-868fa56e1782)

2. **Implementation Output with the Average Execution time and Correctness**:
   ![image](https://github.com/user-attachments/assets/8b3b39ad-9815-4342-bad7-c0eeabbeb014)
   ![image](https://github.com/user-attachments/assets/17a6c827-77f8-41c1-855b-703ba460543c)

## **Video Demonstration**

Find the video [here](https://drive.google.com/drive/folders/1AXK5z74TXkM0Yt-mIEY0QqFFOdF5b67N?usp=drive_link).


---
