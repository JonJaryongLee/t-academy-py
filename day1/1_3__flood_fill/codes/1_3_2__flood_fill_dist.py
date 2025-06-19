import queue


class Point:
    def __init__(self, y, x):
        self.y = y
        self.x = x


# 방향배열
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
board = [[0] * 4 for _ in range(4)]
visited = [[0] * 4 for _ in range(4)]


def bfs(st):
    q = queue.Queue()
    visited[st.y][st.x] = 1
    q.put(st)

    while not q.empty():
        current = q.get()
        for i in range(4):
            np = Point(current.y + dy[i], current.x + dx[i])
            if np.y < 0 or np.y >= 4 or np.x < 0 or np.x >= 4:
                continue
            if visited[np.y][np.x]:
                continue
            visited[np.y][np.x] = visited[current.y][current.x] + 1
            q.put(np)


st = Point(1, 1)
bfs(st)