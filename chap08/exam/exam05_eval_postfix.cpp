#include <iostream>
#include <stack>
#include <string>
#include <limits.h>
using namespace std;

// 후위표기법을 계산하여 결과를 반환합니다.
int eval_postfix(string postfix)
{
    stack<int> stk;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            stk.push(ch - '0'); // 정수로 변환하기 위해 '0'을 빼줌
        }
        else
        {
            int op_right = stk.top(); // 오른쪽 피연산자
            stk.pop();
            int op_left = stk.top(); // 왼쪽 피연산자
            stk.pop();
            switch (ch)
            {
            case '+': // 더하기 결과를 스택에 넣기
                stk.push(op_left + op_right);
                break;
            case '-': // 빼기 결과를 스택에 넣기
                stk.push(op_left - op_right);
                break;
            case '*': // 곱하기 결과를 스택에 넣기
                stk.push(op_left * op_right);
                break;
            case '/': // 나누기 결과를 스택에 넣기
                stk.push(op_left / op_right);
                break;
            }
        }
    }

    // 최종 계산 결과가 스택의 꼭대기에 있습니다.
    if (stk.size() == 1)
    {
        return stk.top();
    }

    return 0; // "" 수식은 0을 반환합니다.
}

int main()
{
    cout << eval_postfix("12-3+") << endl;
    cout << eval_postfix("15-3+") << endl;
    cout << eval_postfix("153-+") << endl;

    return 0;
}
