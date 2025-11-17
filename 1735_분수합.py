# from math import gcd

# a/b
a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

# 먼저 분수의 합을 구하기
b = b1 * b2
a = b1 * a2 + b2 * a1

# 유클리드 호제법
# a > b
# gcd(a, b) = gcd(b, a % b)
# b = 0이 되면 그때의 a가 최대공약수

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

g = gcd(a, b)
print(a // g, b // g)