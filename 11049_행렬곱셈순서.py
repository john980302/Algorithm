

# 변수 설정 및 입력
n = int(input())
matrix = []
dp = [[0] * n for i in range(n)]

for i in range(n):
    r, c = map(int, input().split())
    matrix.append([r, c])

for i in range(1, n):
    for j in range(n - i):
        row, col = j, j + i
        dp[row][col] = 10e9
        for k in range(row, col):
            dp[row][col] = min(dp[row][col], dp[row][k] + dp[k + 1][col] + matrix[row][0] * matrix[k][1] * matrix[col][1])

'''for i in range(len(dp)):
    for j in range(len(dp[0])):
        print(dp[i][j], end=' ')
    print()
'''
print(dp[0][-1])



