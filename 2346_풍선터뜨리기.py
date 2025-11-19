
import sys
from collections import deque

n = int(sys.stdin.readline())
balloons = map(int, sys.stdin.readline().split())
balloon_pairs = deque([(idx + 1, balloon) for idx, balloon in enumerate(balloons)])

balloon_idx = 1
while len(balloon_pairs) > 0:

    # print(balloon_pairs)

    # 이동할 값 가져오기
    balloon_idx, move = balloon_pairs[0]

    # 삭제
    balloon_pairs.popleft()

    # 출력
    print(balloon_idx, end = ' ')

    # 이동
    # deque.rotate(n): n 양수, 시계방향 / 음수, 반시계방향
    move = -(move - 1) if move > 0 else -(move)
    balloon_pairs.rotate(move)

print()
