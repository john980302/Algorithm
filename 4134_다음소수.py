test_case_num = int(input())

for _ in range(test_case_num):
    # 0 <= n <= 4 * 10**9
    start_n = int(input())

    if start_n in [0, 1]:
        print(2)
        continue
    
    n = start_n
    is_end = False
    while not is_end:

        # 소수 여부 판단
        is_end = True
        for i in range(2, int(n**(1/2)) + 1, 1):
            if n % i == 0:
                is_end = False
                n += 1
                break
    
    print(n)
