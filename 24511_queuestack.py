import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
c = list(map(int, sys.stdin.readline().split()))

# queue를 여러 개 붙여도 queue
# stack을 중간에 넣어서 pop을 하면 결과에 영향을 안주니 무시가능

for i in range(len(b) - 1, -1, -1):
    if a[i] == 0 and m > 0:
        print(b[i], end =' ')
        m -= 1

for i in range(0, m, 1):
    print(c[i], end=' ')

print()