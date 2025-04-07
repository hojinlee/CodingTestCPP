#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool is_palindrome(deque<char> dq)
{
    // 덱에 원소가 하나가 남거나 없을 때까지 비교
    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
            return false;

        dq.pop_front();
        dq.pop_back();
    }

    return true;
}

int main()
{
    cout << is_palindrome({'a', 'b', 'b', 'a', 'b'}) << endl;
    cout << is_palindrome({'a', 'b', 'b', 'a'}) << endl;

    return 0;
}