# Open the file for writing
with open("mat_A_data.txt", "w") as file:
    # Generate and write the 8x8 matrix in row-major order
    value = 1
    for i in range(2500):
        for j in range(3000):
            file.write(f"{value} ")
            value = value+1

print("2500x3000 matrix successfully written to mat_A_data.txt in 1D format.")