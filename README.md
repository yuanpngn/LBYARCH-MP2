# LBYARCH-MP2
--------------
#### PANGAN, Yumi Ann S. 
#### Delos Reyes, Carl Justin 
##### [LBYARCH S_11]
---
# **Dot Product Kernel Using C and x86-64 Assembly**

## **Project Overview**
This project implements a dot product kernel for two vectors `A` and `B` using both:
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

1. Clone the repository:
   ```
   git clone https://github.com/LBYARCH-MP2/dot-product-kernels.git
   cd dot-product-kernels
   ```
2. Compile the program:
###  2.1: For `Actual_DP_Solving.c`
     ```bash
     nasm -f elf64 -o DP_asm.o DP_asm.asm
     ```
     ```bash
     gcc -o Actual_DP_Solving.exe Actual_DP_Solving.c DP_asm.obj -lm
     ```
###  2.2: For `DP.c`
     ```bash
     gcc -o DP.exe DP.c DP_asm.obj -lm
     ```
3. Run the program:
### 3.1: For `Actual_DP_Solving.c`
   ```bash
   Actual_DP_Solving.exe
   ```
###  3.2: For `DP.c`
   ```bash
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
C Kernel | Size: 1048576 | Avg Time: 1.000 ms | Result: 2566510280.000000
ASM Kernel | Size: 1048576 | Avg Time: 1.000 ms | Result: 2566510280.000000
Correctness Check: PASSED
Speedup: 1.00x
```

---

## Performance Analysis of Dot Product Calculation

This document provides an analysis of the performance of two different implementations of the dot product calculation. The two implementations are written in C and Assembly (ASM). We compare how fast each implementation runs with different vector sizes and calculate the speedup of the C version over the Assembly version. The goal is to understand the performance of each version for different vector sizes and analyze which one performs better under various conditions.

### **Performance Table**

| Vector Size | Avg Time (C) | Avg Time (Assembly) | Speedup |
|-------------|--------------|---------------------|---------|
| 2^20        | 1.000 ms     | 1.000 ms            | 1.00x   |
| 2^21        | 2.000 ms     | 2.000 ms            | 1.00x   |
| 2^22        | 5.000 ms     | 7.000 ms            | 0.71x   |
| 2^23        | 9.000 ms     | 10.000 ms           | 0.90x   |
| 2^24        | 19.000 ms    | 19.000 ms           | 1.00x   |
| 2^25        | 36.000 ms    | 37.000 ms           | 0.97x   |
| 2^26        | 72.000 ms    | 78.000 ms           | 0.92x   |
| 2^27        | 146.000 ms   | 152.000 ms          | 0.96x   |
| 2^28        | 368.000 ms   | 383.000 ms          | 0.96x   |

### Key Observations

#### 1. Correctness
- The correctness of both implementations was checked by comparing the results. For all vector sizes tested, both the C and ASM versions gave the same results for the dot product calculation. This confirms that both implementations are functioning correctly and produce the expected output.

#### 2. Performance
- **Smaller Vector Sizes**:
  - For smaller vector sizes, such as 2^20 (1,048,576 elements) and 2^21 (2,097,152 elements), both the C and ASM versions performed very similarly. The average times for both versions were almost the same, and the speedup was 1.00x, meaning that neither version was noticeably faster than the other for these smaller sizes. This suggests that for these small vector sizes, both implementations are efficient and can handle the computation with little difference in performance.
  
- **Larger Vector Sizes**:
  - As the vector size increased, the performance difference between the C and ASM versions started to appear. For example, at vector size 2^22 (4,194,304 elements), the speedup of the C version dropped to 0.71x. This means that the ASM version was slightly slower than the C version for this size, and for even larger sizes (e.g., 2^23 and above), the performance gap between the two implementations became even smaller. At sizes like 2^24 (16,777,216 elements), the speedup was 1.00x again, and for even larger sizes like 2^28, the C and ASM kernels took almost the same amount of time.
  
- **Possible Reasons for Performance Trends**:
  - The performance of both versions seems to become more similar as the vector size increases. This could be due to several factors:
    - **Overhead in Assembly**: While Assembly is usually considered faster because it allows low-level control of the processor, the overhead of managing large data sets or the complexity of the assembly code might slow down the ASM kernel as the size of the vector grows.
    - **C Optimizations**: The C compiler might optimize the C code better for large vector sizes, leading to similar or better performance compared to ASM for large inputs.
    - **Hardware Limitations**: The speedup of the C kernel over ASM becomes less significant at larger sizes, possibly because modern processors are optimized to handle C code very efficiently, reducing the difference in performance between the two implementations.

### Conclusion

- **Correctness**: Both the C and Assembly implementations were correct. The results matched in all tests, confirming that both kernels were implemented correctly and produced the expected dot product values.
  
- **Performance**:
  - For smaller vector sizes (2^20 and 2^21), the performance of the C and ASM implementations was almost the same, with no significant difference in execution time. Both kernels completed the dot product calculation quickly and efficiently.
  - As the vector size increased, the performance difference between the two implementations began to emerge. The C kernel was sometimes slightly faster, while the Assembly version had slower or comparable performance at larger vector sizes. The speedup of the C kernel over ASM decreased as the vector size grew.
  - For very large vector sizes (e.g., 2^28), both versions took nearly the same amount of time to complete, and the speedup of the C version was minimal (close to 1.00x). This suggests that while Assembly can be faster for smaller computations, the C version is more efficient for handling large data sizes due to better optimizations and less overhead.

- **Final Thoughts**:
  - The results show that while Assembly can be advantageous for small computations, the C version performs just as well or even better for large vectors. The C implementation benefits from optimizations made by modern compilers and processor architectures, making it more efficient for large-scale computations.
  - For future improvements, further optimization of the Assembly code, or exploring hybrid approaches (using both C and ASM), could potentially provide better performance for large vector sizes.

This analysis helps understand how C and Assembly compare for the dot product calculation and provides insights into when to use each implementation based on the size of the data being processed.


---

## **Screenshots**
1. **C Implementation Output**:
   _[Insert Screenshot of Output Here]_

2. **Assembly Implementation Output**:
   _[Insert Screenshot of Output Here]_

---

## **Video Demonstration**
A short video showcasing:
- Source code explanation.
- Compilation process.
- Program execution and output.
Find the video [here](https://your-video-link).

---
