n, k = map(int, input().split())

result = set()
for i in range(1, n // 2 + 2):
    div, mod = n // i, n % i
    if mod == 0:
        result.add(i)
        result.add(div)

result = list(result)
result.sort()

if len(result) < k:
    print(0)
else:
    print(result[k-1])