#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Member
{
    int id;
    string name;
};

struct compare
{
    bool operator()(Member a, Member b)
    {
        return a.name > b.name;
    }
};

priority_queue<Member, vector<Member>, compare> pq;

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    pq.push({3, "박진수"});
    pq.push({1, "김세빈"});
    pq.push({2, "유하명"});

    while (!pq.empty())
    {
        Member now = pq.top();
        pq.pop();
        cout << now.id << ":" << now.name << " " << '\n';
    }
}