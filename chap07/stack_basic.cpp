#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<int, vector<int>> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << myStack.top() << endl;
    myStack.pop();
    myStack.pop();

    // 스택의 값 출력을 위해 스택이 빌 때까지
    // 꼭대기값을 출력하고 꺼내는 일을 반복
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop(); // 출력한 값은 꺼내기
    }
    cout << endl;

    return 0;
}