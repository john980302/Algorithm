n, k = map(int, input().split())
x_scores = list(map(int, input().split()))

x_scores.sort()

print(x_scores[-k])