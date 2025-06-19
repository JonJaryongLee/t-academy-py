# 5-6-3. PQ operator 구현하기

# 1. 구조체 커스텀 소트

```cpp
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
```

정렬 결과는 오름차순이다.  

```
1 2 3 4
```
- 정수가 들어가는 PQ 는 `<int>` 이며, 문자열일 경우 `<string>` , 구조체일 경우 해당 구조체 타입을 작성  
일단 `greater<int>` 를 빼버리고 내가 만든 `compare` 구조체를 넣었다.  

`compare` 구조체 안에는 `operater` 메서드가 있는데, `()(int a, int b)` 라고 쓰면 메서드 오버로딩을 한다. 쉽게 말하면, 기본으로 쓰이는 `less<>` 라는 오름차순 메서드를 썼지만 그거 대신 이거 쓰겠다는 말이다.  

```cpp
struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
```
비교함수에서 `true` 를 리턴하면 힙의 재정렬이 이루어진다.  

만약 `a == 2 && b == 3` 일 경우, `false` 가 리턴되기에 아무것도 하지 않지만, `a == 3 && b == 2` 일 경우, `true` 가 리턴되어 힙을 재배치한다.  


- `sort()` 와는 부등호 방향이 반대임을 기억하면 된다. 왜냐면 `sort()` 에선 비교함수에서 `true` 를 리턴할 경우 두 수의 정렬이 된 것이므로 swap 할 필요가 없다는 뜻이지만, PQ 에서 비교함수 리턴이 `true` 라면 힙의 재정렬을 하라는 의미이기 때문이다.  


# 2. 구조체 정렬

구조체를 정렬해보자.  

```cpp
struct Member
{
    int id;
    string name;
};
```

위와 같은 구조체가 있고,  

```cpp
pq.push({3, "박진수"});
pq.push({1, "김세빈"});
pq.push({2, "유하명"});
```

다음과 같은 데이터가 주어졌다 가정하자.  

정렬 기준은 다양할 것이다. 아이디 기준으로 정렬할수도 있고, 가나다 순으로 정렬할수도 있다.  

우리가 배웠던 커스텀 소트를 응용하면,  

1. 아이디 기준 오름차순  

```cpp
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
        return a.id > b.id;
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
```

2. 이름 가나다순  

```cpp
struct compare
{
    bool operator()(Member a, Member b)
    {
        return a.name > b.name;
    }
};
```

`id` 가 아니라 `name` 으로 바꿔주면 된다.  


# 3. SWEA 추천 기출 번호
지금까지 배운 내용을 기반으로, 여러분들은 기출 유형 중 "PQ" 를 풀어볼 준비가 되었다.  

데이터셋이 이미 존재하고, 그것을 한번에 정렬해야 할 경우라면 `sort()` 를 사용하는것이 좋지만,  
데이터가 계속 들어오고, 정렬된 상태로 유지해야만 할 때는 PQ 가 유리하다.  

커스텀 정렬 시, `sort()` 와 PQ, 두 정렬 방식의 정렬 기준 함수가 다르며, 부등호 방향도 반대임을 기억하자.   

출제 유형은 다음과 같다.  
1. PQ 단독 사용  
2. BFS 에서 Queue 대신 PQ 사용  
3. Dijkstra - 단독 챕터에서 익히자.  

추천할 문제 목록은 다음과 같다.  

1. 2382 - 미생물 격리 (시뮬레이션으로 풀수도 있지만, BFS + PQ 로도 풀이 가능)  
2. 5653 - 줄기세포 배양 (BFS + PQ)  