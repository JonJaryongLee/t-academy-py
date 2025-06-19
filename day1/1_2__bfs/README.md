# 5-3-1. BFS 이해

# 1. 인접행렬 (맵)  

먼저, 다음의 그래프를 보자.  

![Untitled](./Untitled.png)

문제  

DFS 로 모든 노드를 순회하되, 어떤 과정으로 방문하면서 끝나는지를 출력하라.  

- `level` 사용 금지
- 연결 정보는 행렬로 하드코딩
- 양방향이기 때문에, `visited` 를 활용한다.
- `visited` 원복 불필요, 종료조건으로 항상 들어가던 리턴도 불필요 (!!!)

```
0 1 3 1 4 1 0 2 5 2 6 2 0
```

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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

void func(int cur)
{
    cout << cur << ' ';
    for (int i = 0; i <= 6; i++)
    {
        if (visited[i])
            continue;
        if (arr[cur][i] == 0)
            continue;
        visited[i] = 1;
        func(i);
        cout << cur << ' ';
    }
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    visited[0] = 1;
    func(0);
    cout << '\n';
}
```

- 리턴이 없는데 왜 무한루프에 빠지지 않는가? 갈 수 없는 곳이거나, 이미 방문한 곳이라면 `continue` 되기 때문에, `i == 6` 에서까지 그런 현상이 발생한다면 함수는 더 이상 할 일이 없다. 즉, 리턴이 없어도 끝나버린다.
- `visited` 원복은 왜 안해줬는가? 이 문제는 특정 노드에 다다를때까지 여러 방법을 고민하는 문제가 아니라, 모든 노드를 탐색하는 것이 목적이다. 원복을 하지 않으면 노드를 방문할때마다 방문 처리된다.

그러나, 생각해보면 굉장히 비효율적인 탐색이다. DFS 는 끝까지 들어갔다가 "이전 노드" 로 들어가는 과정이 반드시 포함된다. 따라서 노드의 순회 과정은 다음과 같을수밖에 없다.  

![Untitled](./Untitled%201.png)

```
0 1 3 1 4 1 0 2 5 2 6 2 0
```

그러나, 상식적으로 그럴 필요가 전혀 없다. 이런 식으로 방문하면 훨씬 빠를 것 같다.  

```
0 1 2 3 4 5 6
```

이것이 BFS 이다.  

BFS 는 내가 갈 수 있는 노드를 먼저 간다는 뜻이다.  

아랫쪽으로 향하는 DFS 와는 다르게, 일단 형제 노드를 들린다.  

일단, 틀을 작성해보자.  

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    bfs(0);
}
```

구현을 위해, 큐 자료구조를 사용할 것이다.  

큐는 맨 뒤로 넣고, 맨 앞에서 뺀다.  

![Untitled](./Untitled%202.png)

 위와 같은 방식으로 진행된다.  

이를 위해, 큐에서 제공하는 메서드를 알아야 한다.  

  `Queue.front` : 맨 앞에 있는 것 "확인" (리턴)  

  `Queue.pop` : 맨 앞에 있는 것 "삭제" (리턴 X)  

  `Queue.push` : 맨 뒤에 추가  

  `Queue.empty` : 비어있는지 확인  

이를 기반으로 `bfs` 함수를 만들어보면,  

```cpp
#include <queue>

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
```

결과는?  

```
0 1 2 3 4 5 6
```

# 2. 인접리스트 (벡터)  

배열에 `0` 이 너무 많아 비효율적이므로, 벡터로 바꿔보겠다.  

input 은 다음 형태로 들어온다.  

```cpp
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
```

그리고 벡터엔 다음과 같이 저장될 것이다.  

```
0 {1, 2}
1 {0, 3, 4}
2 {0, 5, 6}
3 {1}
4 {1}
5 {2}
6 {2}
```

이것으로 작성해 본 코드는 다음과 같다.  

```cpp
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
        // ???
    }
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    setVector();
    bfs(0);
}
```

`???` 부분을 바꿔보자.  

```cpp
for (int i = 0; i < v[now].size(); i++)
{
    int next = v[now][i];
    if (visited[next])
        continue;
    visited[next] = 1;
    q.push(next);
}
```

