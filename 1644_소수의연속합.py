def make_prime_list(n):
    a = [False, False] + [True] * (n - 1)
    primes = []

    for i in range(2, n + 1):
        if a[i]:
            primes.append(i)
        for j in range(2 * i, n + 1, i):
            a[j] = False

    return primes

def test():
    n = int(input())
    if n == 1:
        return 0
    prime_list = make_prime_list(n)
    left, right = 0, 0
    sub_s = prime_list[0]
    cnt = 0
    end = len(prime_list)
    while left <= right < end:
        if sub_s < n:
            right += 1
            if right < end:
                sub_s += prime_list[right]
        elif sub_s == n:
            cnt += 1
            sub_s -= prime_list[left]
            left += 1
        elif sub_s > n:
            sub_s -= prime_list[left]
            left += 1
    return cnt

print(test())