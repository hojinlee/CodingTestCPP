#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

// q1가 q2의 하위 집합인지 여부
bool is_subset(queue<int> q1, queue<int> q2)
{
    unordered_set<int> hash_set; // 해시 테이블을 만듭니다. 

    // q2의 모든 원소를 hash_set에 삽입합니다.
    while (!q2.empty())
    {
        hash_set.insert(q2.front());
        q2.pop();
    }

    // q1의 모든 원소가 hash_set에 존재하는 지 확인
    while (!q1.empty())
    {
        // 큐에서 맨 앞 값이 hash_set에 있는지 확인하고 없다면 false를 반환
        if (hash_set.find(q1.front()) == hash_set.end())
        {
            return false;
        }
        q1.pop(); // 있다면 꺼내기
    }

    return true; // 모든 q를 비교하면 true를 반환
}

int main()
{
    queue<int> q1({1, 2, 3}), q2({2, 3, 4, 5, 1});

    cout << is_subset(q1, q2) << endl;

    q1.push(6);
    cout << is_subset(q1, q2) << endl;

    return 0;
}
