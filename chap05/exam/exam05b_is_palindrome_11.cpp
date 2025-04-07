#include <iostream>
#include <list>

using namespace std;

bool is_palindrome_11(const list<int>& nums) 
{
    auto it = nums.begin();
    auto rit = nums.rbegin(); 

    // list의 size함수는 c++11 이상에서 상수 시간에 동작
    int n = nums.size() / 2; // 회문인지 절반의 노드만 확인
    for(int i = 0; i < n; i++, it++, rit++)
    {
        if(*it != * rit) // 대칭 노드의 값이 다르면 회문이 아님
            return false;
    }

    return true;
}

int main() 
{
    cout << is_palindrome_11({}) << endl; 
    cout << is_palindrome_11({1, 2, 3, 2, 1}) << endl;
    cout << is_palindrome_11({1, 2, 3, 3, 2, 1}) << endl;
    cout << is_palindrome_11({1, 2, 3, 3, 1}) << endl;
    cout << is_palindrome_11({1, 2, 3, 3, 3, 1}) << endl;
    
    return 0;
}