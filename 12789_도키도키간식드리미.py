import sys

# 1 <= n <= 1000
n = int(sys.stdin.readline())

first_stack = map(int, sys.stdin.readline().split())
second_stack = []
final_stack = []

# current_human_idx = 1
# while len(first_stack) == 0 and len(second_stack) == 0:

#     human_idx = first_stack[0]

#     if human_idx == current_human_idx:
#         final_stack.append(human_idx)
#         first_stack = first_stack[1:]
#         current_human_idx += 1
    
#     elif len(second_stack) > 0 and second_stack[-1] == current_human_idx:
#         final_stack.append(current_human_idx)
#         current_human_idx += 1
    
#     else:
