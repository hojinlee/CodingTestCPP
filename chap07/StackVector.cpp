#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define STACK_ERROR INT_MIN 
class StackVector
{
private:
    vector<int> m_data;

public:
    StackVector(){}

    bool isEmpty() // 스택이 비어 있는지 
    {
        return m_data.empty();
    }

    int size() { return m_data.size(); } // 스택의 크기 반환

    void push(int value) // 스택에 값 삽입
    {
        m_data.push_back(value);
    }

    int top() // 스택의 꼭대기 값 반환
    {
        if(isEmpty()) return  STACK_ERROR;
        return m_data.back(); // 벡터의 뒤가 스택의 꼭대기
    }

    int pop() // 스택의 꼭대기값을 반환하고 꺼내기
    {
        int ret = top();
        if (ret != STACK_ERROR) m_data.pop_back(); // 스택이 정상이라면 벡터 뒤에서 값 꺼냄
        
        return  ret;
    }

    void show() // 스택의 내용 출력
    {
        // 스택 아래에서 위로 출력
        for (int i: m_data)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    StackVector myStack;
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