#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct Point
{
    int y;
    int x;
};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int map[4][4];
int visited[4][4];

void bfs(Point st)
{
    queue<Point> q;
    visited[st.y][st.x] = 1;
    q.push(st);
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point np = { now.y + dy[i], now.x + dx[i] };
            if (np.y < 0 || np.x < 0 || np.y >= 4 || np.x >= 4)
                continue;
            if (visited[np.y][np.x])
                continue;
            visited[np.y][np.x] = visited[now.y][now.x] + 1;
            q.push(np);
        }
    }
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    Point st = { 1, 1 };
    bfs(st);
}