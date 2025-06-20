import sys
from collections import deque

sys.stdin = open("input.txt", "r")

N, M = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

visited = [False] * N


def bfs(st):
    q = deque()
    visited[st] = True
    q.append(st)

    while q:
        cur = q.popleft()  # deque 의 왼쪽을 꺼냄
        print(cur, end=" ")
        for i in range(M):
            if not visited[i] and board[cur][i] == 1:
                visited[i] = True
                q.append(i)


bfs(0)