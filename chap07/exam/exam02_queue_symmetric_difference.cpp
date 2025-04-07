#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 큐의 내용을 출력
void print_queue(queue<int> q)
{
    // 큐의 원소를 하나씩 거내 출력
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

queue<int> queue_symmetric_difference(queue<int> q1, queue<int> q2)
{
    queue<int> ans;
    int hit[10] = {
        0,
    }; // 두 큐의 중복을 비교하기 위한 테이블

    while (!q1.empty()) // q1에서 발견한 값은 hit테이블에서 증가
    {
        hit[q1.front()]++;
        q1.pop();
    }

    while (!q2.empty()) // q2에서 발견한 값은 hit테이블에서 감소
    {
        hit[q2.front()]--;
        q2.pop();
    }

    for (int i = 0; i < 10; i++)
    {
        if (hit[i] != 0) // 교집합에 속하지 않는다면
            ans.push(i); // 정답 큐에 삽입
    }

    return ans;
}

int main()
{
    queue<int> q1({1, 3, 2});
    queue<int> q2({3, 4, 5});

    queue<int> ans = queue_symmetric_difference(q1, q2);

    print_queue(ans);

    return 0;
}
