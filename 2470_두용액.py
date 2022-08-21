n = int(input())
a = list(map(int, input().split(' ')))

# 정렬
a.sort()

left, right = 0, n - 1
s = 3000000000
lv, rv = 0, 0
while left < right:
    if s > abs(a[left] + a[right]):
        s = abs(a[left] + a[right])
        lv, rv = a[left], a[right]
    if a[left] + a[right] < 0:
        left += 1
    elif a[left] + a[right] > 0:
        right -= 1
    else:
        left += 1
        right -= 1

print(lv, rv)