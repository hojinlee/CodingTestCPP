#include <iostream>
#include <unordered_map>

using namespace std;

// 주어진 문자열에서 만들 수 있는 최대 길이의 회문 문자열의 길이를 반환하는 함수
int longest_palindrome(const string &str)
{
    unordered_map<char, int> hit; // 각 문자의 빈도수를 저장할 unordered_map

    // 주어진 문자열의 각 문자에 대해 그 빈도수를 증가시킵니다.
    for (auto ch : str)
    {
        hit[ch]++;
    }

    int ret = 0; // 결과 값(회문 문자열의 최대 길이)
    int odd = 0; // 홀수 빈도수를 가진 문자의 수

    // hit에 저장된 모든 문자에 대해 순회
    for (auto it = hit.begin(); it != hit.end(); it++)
    {
        if (it->second % 2) // 해당 문자의 빈도수가 홀수인 경우
        {
            odd = 1;               // 홀수 빈도수를 가진 문자가 있다는 것을 표시
            ret += it->second - 1; // 홀수 중 1을 제외한 나머지를 결과 값에 추가
        }
        else
            ret += it->second; // 빈도수가 짝수인 경우 모두 결과 값에 추가
    }
    return odd + ret; // 가장 긴 회문 문자열의 길이 반환
}

int main()
{
    cout << longest_palindrome("ababbc") << endl;    // 5
    cout << longest_palindrome("xxx") << endl;       // 3
    cout << longest_palindrome("ababccbac") << endl; // 7

    return 0;
}