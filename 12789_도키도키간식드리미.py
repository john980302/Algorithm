import sys

# 1 <= n <= 1000
n = int(sys.stdin.readline())

first_stack = list(map(int, sys.stdin.readline().split()))
second_stack = []
final_stack = []

current_human_idx = 1
while len(first_stack) != 0 or len(second_stack) != 0:

    # 1.first_stack에 있는 값이 line을 통과할 수 있는지 확인
    first_idx = first_stack[0] if len(first_stack) > 0 else -1
    if first_idx == current_human_idx:
        final_stack.append(first_idx)
        first_stack = first_stack[1:]
        current_human_idx += 1
        continue
    
    # 2. second_stack에 있는 값이 line을 통과할 수 있는지 확인
    second_idx = second_stack[-1] if len(second_stack) > 0 else -1
    if second_idx == current_human_idx:
        final_stack.append(second_idx)
        second_stack.pop()
        current_human_idx += 1
        continue

    # 3. second_stack에 쌓아야하는 경우
    if first_idx != -1:
        second_stack.append(first_idx)
        first_stack = first_stack[1:]
        continue

    break

if len(final_stack) == n:
    print('Nice')
else:
    print('Sad')
