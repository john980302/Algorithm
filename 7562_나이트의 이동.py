from collections import deque

# 나이트 이동 방향
directions = [[2, 1], [1, 2],
              [-1, 2], [-2, 1],
              [2, -1], [1, -2],
              [-1, -2], [-2, -1]]

def bfs():
    # 체스판 한변의 길이(l), 처음위치(str_x, str_y), 도착위치(end_x, end_y) 입력
    l = int(input())
    str_x, str_y = map(int, input().split())
    end_x, end_y = map(int, input().split())

    # 처음위치와 도착위치가 동일한 경우
    if (str_x == end_x) and (str_y == end_y):
        return 0

    # deque과 체스판 생성
    dq = deque()
    chess = [[0 for i in range(l)] for j in range(l)]

    # 이동할 곳 deque에 입력
    dq.append([str_x, str_y])

    # 이동하기
    while dq:

        # deque에서 처음 값 꺼내기
        cur_x, cur_y = dq.popleft()

        for dx, dy in directions:
            new_x = cur_x + dx
            new_y = cur_y + dy
            # 이동한 위치가 체스판 안의 여부 판단
            if (0 <= new_x < l) and (0 <= new_y < l):
                # 이동한 위치가 마지막 위치인지 판단
                if (new_x == end_x) and (new_y == end_y):
                    chess[new_x][new_y] = chess[cur_x][cur_y] + 1
                    return chess[new_x][new_y]
                elif not chess[new_x][new_y]:
                    dq.append([new_x, new_y])
                    chess[new_x][new_y] = chess[cur_x][cur_y] + 1


# 테스트 케이스 입력
test_case = int(input())
for t in range(test_case):
    print(bfs())
