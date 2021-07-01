from collections import deque

# 이동 방향
directions = [[0, 1], [1, 0],
              [0, -1], [-1, 0]]

N, M = map(int, input().split())
map_list = [list(map(int, input())) for n in range(N)]
visit = [[[False for m in range(M)] for n in range(N)] for _ in range(2)]

def bfs():
    dq = deque()
    dq.append([0, 0, False])
    ans = 0
    
    while dq:
        # 횟수 증가
        ans += 1
        dq_len = len(dq)
        for _ in range(dq_len):
            # deque의 값 popleft
            cur_x, cur_y, drill = dq.popleft()
            # 현재 위치가 종료 위치이면 종료
            if (cur_x == N - 1) and (cur_y == M - 1):
                return ans
            # 4방향 탐색
            for dx, dy in directions:
                new_x = cur_x + dx
                new_y = cur_y + dy
                # 이동한 위치가 map의 범위 안에 들어옴
                # 이동한 위치를 방문하지 않았으면
                if (0 <= new_x < N) and (0 <= new_y < M) and (not visit[drill][new_x][new_y]):
                    # 이동한 위치의 값 == 0
                    if not map_list[new_x][new_y]:
                        dq.append([new_x, new_y, drill])
                        visit[drill][new_x][new_y] = True
                    # 이동한 위치의 값 != 0
                    # 드릴을 하지 않고
                    elif (map_list[new_x][new_y]) and (not drill):
                        dq.append([new_x, new_y, True])
                        visit[drill][new_x][new_y] = True
    
    # 마지막 지점 도착하지 못한 경우
    return -1


ans = bfs()
if ans != -1:
    print(ans)
else:
    print(-1)




