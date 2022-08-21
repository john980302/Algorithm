import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    k = int(input())
    page = list(map(int, input().split(' ')))

    table = [[0] * k for _ in range(k)]
    for i in range(k - 1):
        table[i][i + 1] = page[i] + page[i + 1]
        for j in range(i + 2, k):
            table[i][j] = table[i][j - 1] + page[j]

    # diagonal
    for d in range(2, k):
        for i in range(k - d):
            j = i + d
            minimum = [table[i][h] + table[h + 1][j] for h in range(i, j)]
            table[i][j] += min(minimum)

    print(table[0][k - 1])