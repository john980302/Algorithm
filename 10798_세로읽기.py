matrix = []
for _ in range(5):
    matrix.append(list(input()))

for i in range(15):
    for j in range(5):
        if i < len(matrix[j]):
            print(matrix[j][i], end="")
print()