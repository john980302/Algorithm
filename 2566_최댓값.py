matrix = []
for _ in range(9):
    matrix.append(list(map(int, input().split())))

max_value = 0
max_row = 0
max_col = 0

for i in range(9):
    for j in range(9):
        if matrix[i][j] > max_value:
            max_value = matrix[i][j]
            max_row = i
            max_col = j

print(max_value)
print(max_row + 1, max_col + 1)