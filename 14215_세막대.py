x, y, z = map(int, input().split())

max_value = max([x, y, z])

# 제일 긴 길이 빼고의 합 길이
b = sum([x, y, z]) - max_value

if max_value < b:
    print(sum([x, y, z]))
else:
    print(2*b - 1)
