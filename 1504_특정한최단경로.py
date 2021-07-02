import heapq
import sys

# 상수
inf = 10 ** 8

def dijkstra(graph, start, end, N):

    # start로부터의 거리 값을 저장
    distances = [inf] * (N + 1)
    distances[start] = 0 # 시작(start) 값은 0으로 설정
    queue = []
    heapq.heappush(queue, [distances[start], start]) # 시작노드부터 탐색 시작

    # queue에 남아있는 노드가 없을 때까지 반복
    while queue:
        # 탐색할 노드, 거리를 가져옴
        cur_dis, cur_node = heapq.heappop(queue)

        # 기존에 있는 거리보다 길면, 갱신 x
        if distances[cur_node] < cur_dis:
            continue

        for new_node, new_dis in graph[cur_node]:
            dis = cur_dis + new_dis # 해당 노드를 거쳐서 지나 가는 경우의 길이
            if dis < distances[new_node]: # 기존 거리보다 작은 경우, 갱신
                distances[new_node] = dis
                heapq.heappush(queue, [dis, new_node]) # 다음 인접 거리를 계산을 위해 큐에 삽입

    return distances[end]

# 입력
N, E = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
for i in range(E):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append([b, c])
    graph[b].append([a, c])
v1, v2 = map(int, sys.stdin.readline().split())


# 출력
first = dijkstra(graph, 1, v1, N)
second = dijkstra(graph, v1, v2, N)
third = dijkstra(graph, v2, N, N)
if (first == inf) or (second == inf) or (third == inf):
    case1 = inf
else:
    case1 = first + second + third

first = dijkstra(graph, 1, v2, N)
second = dijkstra(graph, v2, v1, N)
third = dijkstra(graph, v1, N, N)
if (first == inf) or (second == inf) or (third == inf):
    case2 = inf
else:
    case2 = first + second + third

ans = min(case1, case2)
print(ans if ans != inf else -1)