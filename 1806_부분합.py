
n, s = map(int, input().split(' '))
a = list(map(int, input().split(' ')))


def sub_sum(a, n, s):

    size = 1e9
    sub_s = a[0]
    left, right = 0, 0
    while left <= right < n:
        if sub_s < s:
            right += 1
            if right < n:
                sub_s += a[right]
        elif sub_s == s:
            size = min(size, right - left + 1)
            right += 1
            if right < n:
                sub_s += a[right]
        else:
            size = min(size, right - left + 1)
            sub_s -= a[left]
            left += 1

    return size if size != 1e9 else 0


print(sub_sum(a, n, s))







