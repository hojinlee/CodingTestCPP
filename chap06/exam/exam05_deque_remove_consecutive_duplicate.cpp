#include <iostream>
#include <deque>
#include <string>
using namespace std;

// 연속된 중복 문자 중 하나만 남기고 제거 
string remove_consecutive_duplicates(string str)
{
    deque<char> dq;
    string ans("");

    for (char c : str) 
    {
        // 덱이 비었거나 덱의 뒤가 현재 문자와 같다면
        if (dq.empty() || dq.back() != c)
        {
            dq.push_back(c);
        }
    }

    // 덱이 빌 때 까지
    while (!dq.empty())
    {
        ans += dq.front(); // 덱의 앞에서 꺼내서 정답에 붙임
        dq.pop_front();
    }

    return ans;
}

int main()
{
    cout << remove_consecutive_duplicates("Hellllllo") << endl;
    cout << remove_consecutive_duplicates("goooood    booooy") << endl;

    return 0;
}
