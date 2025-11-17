a, b = map(int, input().split())

# 최대공약수
max_div_value = 1
for i in range(2, min(a, b) + 1, 1):
    if a % i == 0 and b % i == 0:
        max_div_value = i

# a * b / 최대공약수
print(int(a * b / max_div_value))