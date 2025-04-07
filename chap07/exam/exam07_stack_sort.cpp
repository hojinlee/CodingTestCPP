#include <iostream>
#include <stack>
using namespace std;

// 스택에 값을 정렬된 상태로 삽입
void insert(stack<int> &s, int val)
{
    // 스택이 비웠거나 꼭대기 값보다 삽입하려는 값이 크거나 같으면 스택에 삽입
    if (s.empty() || s.top() <= val)
    {
        s.push(val);
    }
    else // 삽입하려는 값이 작으면
    {
        int cur = s.top(); // 꼭대기 값을 꺼내고
        s.pop();
        insert(s, val); // 현재 값을 정렬되도록 적절한 위치에 삽입
        s.push(cur);    // 이전 꼭대기 값을 다시 넣습니다.
    }
}

// 스택 정렬
void sort_stack(stack<int> &s)
{
    if (!s.empty())
    {
        int cur = s.top();
        s.pop();
        sort_stack(s);  // 꼭대기 값을 뺀 나머지 스택을 정렬
        insert(s, cur); // 꼭대기 값을 스택의 정렬된 위치에 삽입
    }
}

int main()
{
    stack<int> s({5, 2, 7, 8});

    sort_stack(s);

    // 졍렬된 스택의 값을 출력
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
