n = int(input())

start_value = 2

for _ in range(n):
    start_value += (start_value - 1)

print(start_value ** 2)