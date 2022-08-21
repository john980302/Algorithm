n = int(input())
a = list(map(int, input().split(' ')))
x = int(input())
cnt = 0
# 정렬
a.sort()

# 투 포인트 합 계산
left, right = 0, n - 1
while left < right:
    if a[left] + a[right] == x:
        cnt += 1
        left += 1
        right -= 1
    elif a[left] + a[right] < x:
        left += 1
    else:
        right -= 1

print(cnt)
