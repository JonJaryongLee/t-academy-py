import sys
from collections import deque

sys.stdin = open("input.txt", "r")

N, edge = map(int, sys.stdin.readline().split())
input_edges = [list(map(int, sys.stdin.readline().split())) for _ in range(edge)]

visited = [False] * N

v = [[] for _ in range(N)]
for a, b in input_edges:
    v[a].append(b)


def bfs(st):
    q = deque()
    visited[st] = True
    q.append(st)

    while q:
        now = q.popleft()
        print(now, end=" ")
        # 현재 노드 now와 인접한 모든 노드를 확인
        for next_node in v[now]:
            if visited[next_node]:
                continue
            visited[next_node] = True
            q.append(next_node)


bfs(0)