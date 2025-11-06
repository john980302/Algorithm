n = int(input())

xs, ys = [], []
for _ in range(n):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)


max_x = max(xs)
min_x = min(xs)
max_y = max(ys)
min_y = min(ys)

rectangle_area = (max_x - min_x) * (max_y - min_y)
print(rectangle_area)

