#include <iostream>
using namespace std;

bool helper(string s)
{
    // 종료 조건: 길이가 1이하인 경우는 항상 회문으로 처리
    if (s.size() <= 1)
        return true;

    if (s[0] != s.back()) // 문자열 양 끝을 비교하고
        return false;     // 다르면 회문이 아니다

    // 종료 조건이 아니고 문자열 양 끝이 같으면
    // 가운데 부분을 재귀적으로 검사한다
    return helper(s.substr(1, s.size() - 2));
}

// 전달된 문자열이 회문이면 1, 아니면 0을 반환한다
bool isPalindrome(string s)
{
    string tmp("");

    for (int i = 0; i < s.size(); i++)
    {
        // 문자열 s에서 영문자만 추출해서 tmp에 저장한다
        if (isalpha(s[i]))
            tmp += s[i];
    }

    // tmp가 회문인지 검사해서 결과를 반환한다
    return helper(tmp);
}

int main()
{
    cout << isPalindrome("a, bc, ba.") << endl;  // 1
    cout << isPalindrome("abc, c b. a") << endl; // 1
    cout << isPalindrome("abc, bba") << endl;    // 0
    return 0;
}