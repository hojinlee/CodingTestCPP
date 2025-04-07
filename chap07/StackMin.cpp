#include <iostream>
#include <stack>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define STACK_ERROR INT_MIN
class StackMin
{
private:
    stack<int> m_stkMain; // 삽입 스택
    stack<int> m_stkMin;  // 최솟값 스택
public:
    StackMin()
    {
        // 초기 최솟값으로 가장 작은 정수값 설정
        m_stkMin.push(INT_MAX);
    }

    bool isEmpty() // 스택이 비어 있는지
    {
        return m_stkMain.empty();
    }

    int size() { return m_stkMain.size(); }; // 스택의 크기 반환

    void push(int value) // 스택에 값 삽입
    {
        if (m_stkMin.top() >= value)
        {
            m_stkMin.push(value);
        }
        m_stkMain.push(value);
    }

    int top() // 스택의 꼭대기 값 반환
    {
        return m_stkMain.top();
    }

    int min() // 최솟값 반환
    {
        return m_stkMin.top();
    }

    void pop() // 삽입 스택의 꼭대기값을 꺼내기
    {
        if (m_stkMain.top() == m_stkMin.top())
        {
            // 2 스택의 꼭대기가 같으면 최솟값 스택의 꼭대기값도 제거
            m_stkMin.pop();
        }
        m_stkMain.pop();
    }
};

int main()
{
    StackMin mtStack;
    mtStack.push(4);
    cout << mtStack.min() << endl;
    mtStack.push(2);
    cout << mtStack.min() << endl;
    mtStack.push(3);
    cout << mtStack.min() << endl;

    cout << mtStack.top() << endl;
    mtStack.pop();

    cout << mtStack.top() << endl;
    mtStack.pop();

    mtStack.push(5);
    cout << mtStack.min() << endl;

    return 0;
}