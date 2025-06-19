import sys

# 실제 시험에선 주석 처리 필요
sys.stdin = open("input.txt", "r")


class Point:
    def __init__(self, y, x):
        self.y = y
        self.x = x


# 방향배열
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# 입력
N, M = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
sy, sx = map(int, sys.stdin.readline().split())

# 풀이
sp = Point(sy, sx)

sum_val = 0

for i in range(4):
    ny = sp.y + dy[i]
    nx = sp.x + dx[i]
    # 맵을 벗어날 경우
    if ny < 0 or nx < 0 or ny >= N or nx >= M:
        continue
    sum_val += board[ny][nx]

# 출력
print(sum_val)
