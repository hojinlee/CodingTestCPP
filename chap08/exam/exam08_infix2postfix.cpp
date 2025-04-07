#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 연산자 우선 순위
int get_precedence(char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }

    return 0;
}

// 중위 표기를 후위 표기로 변환
string infix2postfix(string infix)
{
    stack<char> stk;
    string postfix;
    for (char ch : infix)
    {
        if (isdigit(ch)) // 숫자일때
        {
            postfix += ch;
            continue;
        }

        switch (ch)
        {
        // 연산자일 때
        case '+':
        case '-':
        case '*':
        case '/':
            // 스택이 비어 있지 않고 열린 괄호가 아닌 동안
            while (!stk.empty() && stk.top() != '(' &&
                   // 스택 꼭대기의 우선 순위가 현재 연산자 이상인 동안
                   get_precedence(stk.top()) >= get_precedence(ch))
            {
                // 스택의 꼭대기 값을 결과 문자열에 더합니다.
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
            break;

        case '(': // 여는 괄호
            stk.push(ch);
            break;

        case ')': // 닫는 괄호
            // 여는 괄호 직전까지 값을 꺼내서 결과 문자열에 더합니다.
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }

            // 닫는 괄호를 다 처리했으니, 여는 괄호를 스택에서 제거합니다.
            if (!stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else // 일치하는 여는 괄호를 찾지 못했습니다.
            {
                // 잘못된 표기법
                return "err";
            }
            break;
        }
    }

    // 스택이 빌 때 까지 남아 있는 문자를 결과에 더합니다.
    while (!stk.empty())
    {
        if (stk.top() == '(')
        {
            // 잘못된 표기법
            return "err";
        }
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int main()
{
    cout << infix2postfix("1+2*3") << endl;
    cout << infix2postfix("(1-2)/3") << endl;
    cout << infix2postfix("(1-2)/3(") << endl;
    cout << infix2postfix("1-2)/3") << endl;

    return 0;
}
