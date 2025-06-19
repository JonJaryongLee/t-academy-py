#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[7];
int visited[7];

int N = 7;
int edge = 12;
int input[12][2] = {
    0, 1,
    0, 2,
    1, 0,
    1, 3,
    1, 4,
    2, 0,
    2, 5,
    2, 6,
    3, 1,
    4, 1,
    5, 2,
    6, 2,
};

void setVector()
{
    for (int i = 0; i < edge; i++)
    {
        v[input[i][0]].push_back(input[i][1]);
    }
}

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
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (visited[next])
                continue;
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    setVector();
    bfs(0);
}