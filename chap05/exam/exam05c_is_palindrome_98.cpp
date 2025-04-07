#include <iostream>
#include <list>

using namespace std;

bool is_palindrome_98(const list<int> &nums)
{
    auto it = nums.begin();
    auto rit = nums.rbegin();

    // it를 reverse_iterator로 바꿔야 동일한 위치인지 확인 가능
    while (list<int>::const_reverse_iterator(it) != rit) // 홀수 길이일 때 같은 노드인지 비교
    {
        if (*it != *rit) // 대칭 노드의 값이 다르면 회문이 아님
            return false;

        it++;
        // 전체 길이가 짝수인 경우 다음 it와 비교
        if (list<int>::const_reverse_iterator(it) == rit)
            break;
        rit++;
    }

    return true;
}

int main()
{
    cout << is_palindrome_98({}) << endl;
    cout << is_palindrome_98({1, 2, 3, 2, 1}) << endl;
    cout << is_palindrome_98({1, 2, 3, 3, 2, 1}) << endl;
    cout << is_palindrome_98({1, 2, 3, 3, 1}) << endl;
    cout << is_palindrome_98({1, 2, 3, 3, 3, 1}) << endl;

    return 0;
}