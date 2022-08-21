from itertools import combinations

n, c = map(int, input().split(' '))
items = list(map(int, input().split(' ')))

list_a = items[:n//2]
list_b = items[n//2:]

len_a, len_b = len(list_a), len(list_b)

sub_a, sub_b = [], []

for num in range(len_a + 1):
    for sub_set in combinations(list_a, num):
        sub_a.append(sum(sub_set))

for num in range(len_b + 1):
    for sub_set in combinations(list_b, num):
        sub_b.append(sum(sub_set))

sub_a.sort()

answer = 0

# 정렬된 요소에 이분탐색 시행
for element_b in sub_b:
    # 용량보다 큰 경우
    if element_b > c:
        continue

    # 이분 탐색
    left_idx = 0
    right_idx = len(sub_a)

    # 값을 만족하는 rightmost
    while left_idx < right_idx:
        mid = (left_idx + right_idx) // 2
        if element_b + sub_a[mid] > c:
            right_idx = mid
        else:
            left_idx = mid + 1

    answer += right_idx

print(answer)