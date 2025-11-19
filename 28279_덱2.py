# 덱 구현
# 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
# 2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
# 3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 5: 덱에 들어있는 정수의 개수를 출력한다.
# 6: 덱이 비어있으면 1, 아니면 0을 출력한다.
# 7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
# 8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.

import sys
from collections import deque

# 1 <= n <= 1,000,000
n = int(sys.stdin.readline())

my_deque = deque()

for _ in range(n):
    user_input = sys.stdin.readline().split()

    if user_input[0] == '1':
        my_deque.appendleft(user_input[1])
    
    elif user_input[0] == '2':
        my_deque.append(user_input[1])
    
    elif user_input[0] == '3':
        left_pop = my_deque.popleft() if len(my_deque) > 0 else -1
        print(left_pop)
    
    elif user_input[0] == '4':
        right_pop = my_deque.pop() if len(my_deque) > 0 else -1
        print(right_pop)

    elif user_input[0] == '5':
        print(len(my_deque))
    
    elif user_input[0] == '6':
        is_empty = 1 if len(my_deque) == 0 else 0
        print(is_empty)
    
    elif user_input[0] == '7':
        left_num = my_deque[0] if len(my_deque) > 0 else -1
        print(left_num)
    
    elif user_input[0] == '8':
        right_num = my_deque[-1] if len(my_deque) > 0 else -1
        print(right_num)
