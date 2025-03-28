#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

/*To run this open the folder in power shell give the following command
->to build
	gcc ieee754_matrix.c -o ieee754_matrix -lm
->to run the exe file
	./ieee754_matrix
*/

// Function to print the 32-bit representation of a float
void print_float_bits(FILE *file, float f) {
    uint32_t *p = (uint32_t *)&f;
    fprintf(file, "0x%08X\n", *p);
}

// Function to allocate a 2D float matrix
#define ALLOC_MATRIX(rows, cols) ((float **)allocate_matrix(rows, cols))
void **allocate_matrix(int rows, int cols) {
    void **matrix = malloc(rows * sizeof(void *));
    if (!matrix) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(float));
        if (!matrix[i]) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Function to free a 2D matrix
void free_matrix(void **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Set the dimensions
    const int M = 550;
    const int N = 620;
    const int P = 480;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Allocate matrices dynamically
    float **matrix_A = ALLOC_MATRIX(M, N);
    float **matrix_B = ALLOC_MATRIX(N, P);
    float **matrix_C = ALLOC_MATRIX(M, P);

    // Open files for writing
    FILE *float_A_file = fopen("matrix_A_float.txt", "w");
    FILE *float_B_file = fopen("matrix_B_float.txt", "w");
    FILE *float_C_file = fopen("matrix_C_float.txt", "w");

    if (!float_A_file || !float_B_file || !float_C_file) {
        perror("Error opening output files");
        exit(EXIT_FAILURE);
    }

    // Fill matrix_A with random float values and save to file
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix_A[i][j] = ((float)rand() / RAND_MAX) * 20.0f - 10.0f;
            fprintf(float_A_file, "%10.6f ", matrix_A[i][j]);
        }
        //fprintf(float_A_file, "\n");
    }
    fclose(float_A_file);

    // Fill matrix_B with random float values and save to file
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            matrix_B[i][j] = ((float)rand() / RAND_MAX) * 20.0f - 10.0f;
            fprintf(float_B_file, "%10.6f ", matrix_B[i][j]);
        }
        //fprintf(float_B_file, "\n");
    }
    fclose(float_B_file);

    // Matrix multiplication: matrix_C = matrix_A * matrix_B
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            matrix_C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
            fprintf(float_C_file, "%10.6f ", matrix_C[i][j]);
        }
        //fprintf(float_C_file, "\n");
    }
    fclose(float_C_file);

    // Free allocated memory
    free_matrix((void **)matrix_A, M);
    free_matrix((void **)matrix_B, N);
    free_matrix((void **)matrix_C, M);

    printf("Matrix A, B, and C generation Task finished...\n");
    return 0;
}
