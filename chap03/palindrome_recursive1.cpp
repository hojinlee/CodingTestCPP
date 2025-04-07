#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    if (s.size() <= 1)
        return true;
    if (s.front() != s.back())
        return false;
    return isPalindrome(s.substr(1, s.size() - 2));
}

int main()
{
    cout << isPalindrome("abcba") << endl;
    cout << isPalindrome("abccba") << endl;
    cout << isPalindrome("abcbba") << endl;
    return 0;
}