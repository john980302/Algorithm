import heapq
import sys

# 상수
inf = 10 ** 8

def dijkstra(graph, start, V):

    # start로부터의 거리 값을 저장
    distances = [inf] * (V + 1)
    distances[start] = 0 # 시작(start) 값은 0으로 설정
    queue = []
    heapq.heappush(queue, [distances[start], start]) # 시작노드부터 탐색 시작

    # queue에 남아있는 노드가 없을 때까지 반복
    while queue:
        # 탐색할 노드, 거리를 가져옴
        cur_dis, cur_node = heapq.heappop(queue)
        print("cur_dis, cur_node, distances[cur_node]: %d, %d, %d" %(cur_dis, cur_node, distances[cur_node]))
        # 기존에 있는 거리보다 길면, 갱신 x
        if distances[cur_node] < cur_dis:
            continue

        for new_node, new_dis in graph[cur_node]:
            dis = cur_dis + new_dis # 해당 노드를 거쳐서 지나 가는 경우의 길이
            if dis < distances[new_node]: # 기존 거리보다 작은 경우, 갱신
                distances[new_node] = dis
                heapq.heappush(queue, [dis, new_node]) # 다음 인접 거리를 계산을 위해 큐에 삽입

    return distances

# 입력
V, E = map(int, sys.stdin.readline().split())
K = int(sys.stdin.readline())
graph = [[] for _ in range(V + 1)]
for i in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append([v, w])


# 출력
for i in dijkstra(graph, K, V)[1:]:
    print(i if i != inf else "INF")