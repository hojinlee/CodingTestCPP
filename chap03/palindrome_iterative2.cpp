#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < s.size(), j >= 0; i++, j--)
    {
        while (i < s.size() && !::isalpha(s[i]))
            i++;
        while (j >= 0 && !::isalpha(s[j]))
            j--;

        if (i >= j)
            return true;

        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome("a, bc, ba.") << endl;
    cout << isPalindrome("abc, c b. a") << endl;
    cout << isPalindrome("abc, bba") << endl;
    return 0;
}