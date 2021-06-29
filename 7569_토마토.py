from collections import deque

def main():
    # 토마토의 방향 설정
    direction = [[1, 0, 0], [-1, 0, 0],
                 [0, 1, 0], [0, -1, 0],
                 [0, 0, 1], [0, 0, -1]]

    # 입력 및 변수 설정
    m, n, h = map(int, input().split())
    tomato = [[list(map(int, input().split())) for j in range(n)] for k in range(h)]
    dq = deque()
    plus_one = 0
    minus_one = 0
    for k in range(h):
        for j in range(n):
            for i in range(m):
                if tomato[k][j][i] == 1:
                    dq.append([k, j, i])
                    plus_one += 1
                elif tomato[k][j][i] == -1:
                    minus_one += 1

    # 처음부터 다 익은 상태
    if minus_one + plus_one == m * n * h:
        print(0)
        return


    # 알고리즘 수행
    while dq:
        h_, n_, m_ = dq.popleft()
        for dh, dn, dm in direction:
            nh, nn, nm = h_ + dh, n_ + dn, m_ + dm
            # 이동한 값이 범위 안에 들어오는 지 확인
            if (0 <= nh < h) and (0 <= nn < n) and (0 <= nm < m):
                # 이동한 위치에 안 익은 토마토가 있다.
                if tomato[nh][nn][nm] == 0:
                    tomato[nh][nn][nm] = tomato[h_][n_][m_] + 1
                    dq.append([nh, nn, nm])

    # 결과 출력
    max_value = 0
    for tomato_2 in tomato:
        for tomato_1 in tomato_2:
            for tomato_0 in tomato_1:
                if tomato_0 == 0:
                    print(-1)
                    return
                max_value = max(max_value, tomato_0)

    print(max_value - 1)

main()

