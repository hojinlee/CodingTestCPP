#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    int const LEN = s.size();
    for (int i = 0; i < LEN / 2; i++)
    {
        // 문자열의 양 끝에서 안쪽으로 비교
        if (s[i] != s[LEN - i - 1])
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome("abcba") << endl;
    cout << isPalindrome("abccba") << endl;
    cout << isPalindrome("abcbba") << endl;

    return 0;
}