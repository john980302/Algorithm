a, b, c, d, e, f = map(int, input().split())

# x = (c - (f * b) / e) / (a - (b * d) / e)
# y = (c - (a * f) / d) / (b - (e * a) / d)

# print(f'{int(x)} {int(y)}')

for x in range(-999, 999 + 1, 1):
    for y in range(-999, 999 + 1, 1):
        if a * x + b * y == c and d * x + e * y == f:
            print(f'{x} {y}')