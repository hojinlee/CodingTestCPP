#include <iostream>
#include <array>
#include <limits>

using namespace std;

#define CAPACITY 10
// 가장 작은 정수값을 에러값으로 사용
#define STACK_ERROR INT_MIN 
class StackArray
{
private:
    array<int, CAPACITY> m_data;
    
    int m_top; // top의 인덱스(0-based)

public:
    // top의 인덱스를 배열 범위 밖인 -1로 설정. 빈 스택을 의미
    StackArray(): m_top(-1){} 

    bool isEmpty() // 스택이 비어 있는지 
    {
        if (m_top == -1) return true; // top의 인덱스가 -1이면 빈 스택
        return false;
    }

    // 스택의 크기 반환, 배열 인덱스는 0부터 시작해서 1을 더해야 크기
    int size() { return m_top + 1; } 

    bool push(int value) // 스택에 값 삽입
    {
        if (m_top + 1 < CAPACITY) // 새 값을 삽입해도 스택의 용량을 초과하지 않을 때 
        {
            m_data[++m_top] = value; // top인덱스를 증가해서 배열에 값 설정
        }
        else
        {
            // 스택 용량 초과
            cout << "exceeded capacity of this stack" << endl;
            return false;
        }
        return true;
    }

    int top() // 스택의 꼭대기 값 반환
    {
        if (m_top > -1) return m_data[m_top]; // 스택에 정상적으로 값이 존재
        return  STACK_ERROR; // 에러 
    }

    int pop() // 스택의 꼭대기값을 반환하고 꺼내기
    {
        int ret = top();
        if (ret != STACK_ERROR) m_top--; // 스택이 정상이라면 top 인덱스 감소
        
        return  ret;
    }

    void show() // 스택의 내용 출력
    {
        // 스택 아래에서 위로 출력
        for (int i = 0; i <= m_top; i++)
        {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    StackArray myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.show(); 

    cout << myStack.top() << endl;
    myStack.pop();
    myStack.pop();
    myStack.show();
    
    return 0;
}