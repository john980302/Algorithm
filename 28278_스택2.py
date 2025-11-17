# 정수를 저장한는 스택 구현
# 아래 명령 처리 프로그램 작성
# 1 x: 정수 x를 스택에 넣는다. (1 <= x <= 100,000)
# 2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 3: 스택에 들어있는 정수의 개수를 출력한다.
# 4: 스택이 비어있으면 1, 아니면 0을 출력한다.
# 5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. -1을 대신 출력한다.

import sys

# 1 <= N <= 1,000,000
n = int(sys.stdin.readline())
max_point = 0
my_stack = [0] * (n + 1)

for i in range(n):
    user_inputs = (sys.stdin.readline().split())

    # 명령 수행
    if user_inputs[0] == '1':
        my_stack[max_point] = int(user_inputs[1])
        max_point += 1

    elif user_inputs[0] == '2':
        if max_point == 0:
            print(-1)
        else:
            print(my_stack[max_point - 1])
            max_point -= 1

    elif user_inputs[0] == '3':
        print(max_point)
    
    elif user_inputs[0] == '4':
        if max_point == 0:
            print(1)
        else:
            print(0)
    
    elif user_inputs[0] == '5':
        if max_point == 0:
            print(-1)
        else:
            print(my_stack[max_point - 1])