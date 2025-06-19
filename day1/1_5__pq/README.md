# 5-6-2. Priority Queue

# 1. 개요

Queue 는 먼저 넣은 게 최고의 우선순위를 가졌지만,  

PQ (Priority Queue) 는 내가 우선순위를 정한다.  


PQ 를 배울 땐 `sort()` 와 마찬가지로 다음 세 가지 상황이 기본이다. 단, 내림차순 (Max Heap) 이 기본이라는 점을 기억하자.  

1. 내림차순  
2. 오름차순  
3. 구조체 커스텀 정렬  
  

# 2. 내림차순 (Descending Order, DESC)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

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

```
4 3 2 1
```

선언할 때 `queue` 가 아니라 `priority_queue` 로 선언.  

앞에것 확인할 땐 `front` 가 아니라 `top` 메서드 사용  

그래서 하나하나 빼보면,  

넣은 순서가 아니라 오름차순 정렬되서 나오는것을 알 수 있다. 내부적으로 PQ 는 사실 최대 힙 (Max Heap) 으로 구현되어 있기 때문이다.  

# 2. 오름차순 (Ascending Order, ASC)

오름차순을 쓰려면, 선언할 때 이것저것 해줘야한다.  

vector 헤더와, greater (점점 커지는) 라는 메서드가 필요하다.  

선언은 아래와 같다.  

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
```

여기서, 맨 마지막에 있는 `greater<int>` 가 정렬의 기준이 된다.  


```cpp
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
```

```
1 2 3 4
```

물론, A형 (Adv) 시험을 위해선 위 두 가지 내용을 아는 것은 아무 필요가 없다. 가장 중요한 것은 구조체 커스텀 정렬이기 때문이다.  

