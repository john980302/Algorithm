n, m = map(int, input().split())
matrix_a = []
matrix_b = []

for _ in range(n):
    matrix_a.append(list(map(int, input().split())))

for _ in range(n):
    matrix_b.append(list(map(int, input().split())))


for i in range(n):
    for j in range(m):
        print(matrix_a[i][j] + matrix_b[i][j], end=" ")
    print()