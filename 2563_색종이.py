white_paper = [[0 for i in range(100)] for j in range(100)]

n = int(input())

for _ in range(n):
    start_i, start_j = map(int, input().split())
    for i in range(start_i -1, start_i + 9):
        for j in range(start_j -1, start_j + 9):
            white_paper[i][j] = 1

total_area = 0
for i in range(100):
    total_area += sum(white_paper[i])

print(total_area)