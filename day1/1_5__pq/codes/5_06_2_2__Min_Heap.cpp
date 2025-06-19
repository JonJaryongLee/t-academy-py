#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
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