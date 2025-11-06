while True:
    n = int(input())
    if n == -1:
        break

    result = set()
    for i in range(2, n // 2 + 2):
        div, mod = n // i, n % i
        if mod == 0:
            result.add(div)
            result.add(i)
    
    result = list(result)
    result.sort()
    if sum(result) != n - 1:
        print(f'{n} is NOT perfect.')
    else:
        print(f'{n} = 1', end ='')
        for v in result:
            print(f' + {v}', end='')
        print()
