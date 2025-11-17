t = int(input())

def get_prime_key_value(max_n):

    prime_key = []
    prime_value = [0] * max_n
    for n in range(2, max_n + 1, 1):
        is_prime = True
        for i in range(2, int(n**(1/2)) + 1, 1):
            if n % i == 0:
                is_prime = False
                break
        if is_prime:
            prime_key.append(n)
            prime_value[n-1] = 1
    
    return prime_key, prime_value


n_list = []
for _ in range(t):
    n = int(input())

    n_list.append(n)

# 소수 리스트 추출
prime_key, prime_value = get_prime_key_value(1000000)

for n in n_list:

    cnt = 0
    for a in prime_key:

        # prime 값이 n보다 큰 경우에는 종료
        if a > n:
            break

        # n = a + b를 찾으
        # a가 b보다 작은 값만 찾을 것임
        if a > n - a:
            break

        # b = n - a
        # b가 소수이면 cnt 값 1 증가
        if prime_value[n-a-1]:
            cnt += 1

    
    print(cnt)
