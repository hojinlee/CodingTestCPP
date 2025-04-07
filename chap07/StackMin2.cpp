#include <iostream>
#include <stack>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define STACK_ERROR INT_MIN
class StackMin
{
private:
    stack<int> m_stkMain; // 최솟값 관리를 하나의 스택으로
    int m_min;            // 최솟값 정보
public:
    // 초기 최솟값으로 가장 작은 정수값 설정
    StackMin() : m_min(INT_MAX) {}

    bool isEmpty() // 스택이 비어 있는지
    {
        return m_stkMain.empty();
    }

    int size() { return m_stkMain.size(); }; // 스택의 크기 반환

    void push(int value) // 스택에 값 삽입
    {
        if (m_min >= value) // 현재값이 이전 최솟값보다 작거나 같으면
        {
            m_stkMain.push(m_min); // 이전 최솟값을 한 번더 삽입
            m_min = value;         // 최솟값 갱신
        }
        m_stkMain.push(value);
    }

    int top() // 스택의 꼭대기 값 반환
    {
        return m_stkMain.top();
    }

    int min() // 최솟값 반환
    {
        return m_min;
    }

    void pop() // 삽입 스택의 꼭대기값을 꺼내기
    {
        int top = m_stkMain.top();
        m_stkMain.pop();
        //  스택의 꼭대기가 최솟값이면 하나 더 꺼내기
        if (top == m_min)
        {
            m_min = m_stkMain.top();
            m_stkMain.pop();
        }
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