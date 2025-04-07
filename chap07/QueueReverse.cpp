#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 큐 뒤집기
void reverseQueue(queue<int> &que)
{
    // 방향을 뒤집기 위해 스택 사용
    stack<int> stk;
    while (!que.empty()) // 큐가 빌 때까지
    {
        stk.push(que.front()); // 큐의 맨 앞 값을 스택에 넣기
        que.pop();             // 삽입한 큐 값을 꺼내기
    }

    while (!stk.empty()) // 스택이 빌 때까지
    {
        que.push(stk.top()); // 스택 꼭대기 값을 큐에 넣기
        stk.pop();           // 스택에서 꺼내기
    }
}

int main()
{
    queue<int> que({1, 2, 3, 4, 5});

    cout << endl;
    reverseQueue(que);

    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
    return 0;
}