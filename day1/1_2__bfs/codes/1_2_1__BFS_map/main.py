import sys
import queue

sys.stdin = open("input.txt", "r")

N, M = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

visited = [False] * N


def bfs(start):
    q = queue.Queue()  # FIFO 큐 사용
    visited[start] = True
    q.put(start)

    while not q.empty():
        current = q.get()  # 큐의 가장 앞의 정점을 꺼냄
        print(current, end=" ")
        for i in range(M):
            if not visited[i] and board[current][i] == 1:
                visited[i] = True
                q.put(i)


bfs(0)