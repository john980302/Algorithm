# 입력
# 1 <= N <= 1,000,000
# -10^9 <= X_i <= 10^9
N = int(input())
X = list(map(int, input().split(' ')))

# 계산
xx = list(set(X))
xx.sort()
d_x = {}
for i in range(len(xx)):
    d_x[xx[i]] = i

for i in range(N):
    print(d_x[X[i]], end=' ')