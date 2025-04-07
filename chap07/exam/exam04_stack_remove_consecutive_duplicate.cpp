#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// 연속된 중복 문자 중 하나만 남기고 제거
string remove_consecutive_duplicates(string str)
{
    stack<char> stk;
    string ans("");

    for (char c : str)
    {
        // 스택이 비었거나 스택의 꼭대기가 현재 문자와 같다면
        if (stk.empty() || stk.top() != c)
        {
            stk.push(c);
        }
    }

    // 스택이 빌 때 까지
    while (!stk.empty())
    {
        ans += stk.top(); // 스택의 꼭대기에서 꺼내서 정답에 붙임
        stk.pop();
    }

    // 스택은 특성상 값의 순서가 바뀌어서 다시 뒤집어 줘야 합니다.
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << remove_consecutive_duplicates("Helllllleo") << endl;
    cout << remove_consecutive_duplicates("goooood    booooy") << endl;

    return 0;
}
