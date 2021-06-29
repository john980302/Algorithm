from collections import deque

N, K = map(int, input().split())
end_value = (10 ** 5) * 2
dq = deque()
cnt = [0] * (end_value + 1)

def bfs():
    dq.append(N)

    while dq:
        n = dq.popleft()

        # 수빈이가 동생을 찾은 경우
        if n == K:
            print(cnt[n])
            break

        # 할 수 있는 경우의 수 모두 테스트
        # n-1부터 확인하면 n > K인 경우를 확인할 수 있다.
        for x in (n-1, n+1, n*2):
            # 이동한 위치인 x 값이 범위 안에 들어오는 경우
            # 이동한 위치에서의 값이 0인 경우
            if (0 <= x <= end_value) and (not cnt[x]):
                dq.append(x)
                cnt[x] = cnt[n] + 1

bfs()
