import numpy as np

# Function to read a matrix from a file
def read_matrix_from_file(file_name, rows, cols):
    with open(file_name, "r") as file:
        # Read the file and convert into a 1D list of integers
        data = list(map(int, file.read().split()))
        matrix = [[0 for _ in range(cols)] for _ in range(rows)]
        # Reshape it into a 2D matrix
        for i in range(rows):
            for j in range(cols):
                matrix[i][j] = data[i * cols + j]
        return np.array(data).reshape(rows, cols)

# Function to write the matrix to a file
def write_matrix_to_file(matrix, file_name):
    with open(file_name, "w") as file:
        # Write each value separated by a space
        for row in matrix:
            file.write(" ".join(map(str, row)) + " ")

# Main code
def main():
    # Define matrix dimensions (for example, 3x3 matrices)
    rows_A = 550
    cols_A = 620
    rows_B = 620
    cols_B = 480

    with open("mat_A_data.txt", "r") as file:
        # Read matrices from files
        data = list(map(int, file.read().split()))
        A = [[0 for _ in range(cols_A)] for _ in range(rows_A)]

    # Reshape it into a 2D matrix
    for i in range(rows_A):
        for j in range(cols_A):
            A[i][j] = data[i * cols_A + j]

    with open("mat_B_data.txt", "r") as file:
        # Read matrices from files
        data = list(map(int, file.read().split()))
        B = [[0 for _ in range(cols_B)] for _ in range(rows_B)]

    # Reshape it into a 2D matrix
    for i in range(rows_B):
        for j in range(cols_B):
            B[i][j] = data[i * cols_B + j]

    # Perform matrix multiplication
    if cols_A != rows_B:
        print("Matrix multiplication not possible due to incompatible dimensions.")
        return

    # Matrix multiplication
    R = np.dot(A, B)

    # Write the result matrix to matR.txt
    write_matrix_to_file(R, "mat_R_S_data.txt")
    print("Matrix multiplication complete. Result saved to matR.txt.")

if __name__ == "__main__":
    main()
