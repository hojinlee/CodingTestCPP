#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 큐의 앞에서 k개의 원소를 뒤집기
void reverse_first_k(queue<int> &q, int k)
{
    stack<int> stk; // 방향을 뒤집기 위한 스택

    // 방향을 뒤집을 원소만 꺼내서 스택에 넣기
    for (int i = 0; i < k; i++)
    {
        stk.push(q.front()); // 큐의 맨 앞 값을 스택에 넣기
        q.pop();             // 큐에서 꺼내기
    }

    // 스택이 빌 때 까지
    while (!stk.empty())
    {
        q.push(stk.top()); // 스택의 꼭대기에서 꺼내서 큐에 넣기, 역순으로 삽입됨
        stk.pop();         // 스택에서 꺼내기
    }

    // 큐의 앞부분에 있는 정뱡향의 size() - k개의 원소를 꺼내서 디시 큐에 넣습니다.
    for (int i = k; i < q.size(); i++)
    {
        q.push(q.front()); // 큐의 맨 앞 값을 큐의 뒤에 넣기
        q.pop();           // 큐에서 꺼내기
    }
}

int main()
{
    queue<int> q({1, 2, 3, 4, 5});
    reverse_first_k(q, 3);

    // 큐가 빌 때 까지
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
