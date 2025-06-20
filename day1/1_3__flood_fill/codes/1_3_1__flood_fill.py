from collections import deque


class Point:
    def __init__(self, y, x):
        self.y = y
        self.x = x


# 방향배열
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
board = [[0] * 4 for _ in range(4)]
visited = [[False] * 4 for _ in range(4)]


def bfs(st):
    q = deque()
    visited[st.y][st.x] = True
    q.append(st)

    while q:
        cp = q.popleft()
        for i in range(4):
            np = Point(cp.y + dy[i], cp.x + dx[i])
            if np.y < 0 or np.y >= 4 or np.x < 0 or np.x >= 4:
                continue
            if visited[np.y][np.x]:
                continue
            visited[np.y][np.x] = True
            q.append(np)


st = Point(1, 1)
bfs(st)
