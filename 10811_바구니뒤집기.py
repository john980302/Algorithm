n, m = map(int, input().split())
basket = [i for i in range(1, n + 1)]

for _ in range(m):
    i, j = map(int, input().split())
    one = basket[:i - 1]
    two = basket[i - 1:j]
    two.reverse()
    three = basket[j:]
    basket = one + two + three

for ball in basket:
    print(ball, end=" ")