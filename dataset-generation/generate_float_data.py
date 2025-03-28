import numpy as np

def save_matrix_as_float(file_name, matrix):
    with open(file_name, 'w') as f:
        f.write(' '.join(f"{x:.6f}" for x in matrix.flatten(order='C')) + '\n')

def save_matrix_as_hex(file_name, matrix):
    with open(file_name, 'w') as f:
        f.write(' '.join(f"0x{np.float32(x).view(np.uint32):08X}" for x in matrix.flatten(order='C')) + '\n')

def main():
    M, N, P = 16, 12, 8  # Dimensions: A is MxN, B is NxP

    # Generate random float matrices A and B
    A = np.random.uniform(-100.0, 100.0, (M, N)).astype(np.float32)
    B = np.random.uniform(-100.0, 100.0, (N, P)).astype(np.float32)

    # Matrix multiplication C = A * B
    C = np.matmul(A, B)

    # Save matrices A and B to separate files (float and hex)
    save_matrix_as_float('matrix_A_float.txt', A)
    save_matrix_as_hex('matrix_A_hex.txt', A)

    save_matrix_as_float('matrix_B_float.txt', B)
    save_matrix_as_hex('matrix_B_hex.txt', B)

    # Save the result matrix C to separate files (float and hex)
    save_matrix_as_float('matrix_C_float.txt', C)
    save_matrix_as_hex('matrix_C_hex.txt', C)

    print("Matrices A, B, and their product C have been saved in float and hex formats.")

if __name__ == '__main__':
    main()
