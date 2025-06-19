#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

priority_queue<int, vector<int>, compare> pq;

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(4);

    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        cout << now << " ";
    }
}