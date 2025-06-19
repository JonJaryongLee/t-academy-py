#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int arr[7][7] = {
    0, 1, 1, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 1, 1,
    0, 1, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0,
};

int visited[7];

void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for (int i = 0; i < 7; i++)
        {
            if (visited[i])
                continue;
            if (arr[now][i] == 0)
                continue;
            visited[i] = 1;
            q.push(i);
        }
    }
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    bfs(0);
}