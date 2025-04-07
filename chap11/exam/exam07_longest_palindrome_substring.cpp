#include <iostream>
#include <vector>
using namespace std;

// 현재 위치에서 가장 긴 회문 찾기
// str: 전체 문자열, left: 부분 문자열의 왼쪽, right: 부분 문자열의 오른쪽
string longest_palindrome(string str, int left, int right)
{
    // 부분 문자열의 왼쪽과 오른쪽이 전체 문자열의 범위를 벗어나지 않는 범위에서
    // 왼쪽과 오른쪽이 같은 동안 반복
    while (0 <= left && right < str.size() && str[left] == str[right])
    {
        left--;  // 왼쪽으로 이동
        right++; // 오른쪽으로 이동
    }

    // while 탈출 조건은 범위 밖이라, left에 1을 더하고 right에 1을 빼야 합니다.
    return str.substr(left + 1, right - left - 1);
}

// 부분 문자열 중 가장 긴 회문 찾기
string longest_palindrome_substring(const string &str)
{
    const int N = str.size(); // 전체 문자열의 길이
    if (N <= 1)               // 문자열의 길이가 1이하면 전체문자열이 회문
        return str;           // 전체 문자열 그대로 반환

    string str_max(""); // 최장 회문
    string str_cur(""); // 현재 회문
    int len_max(0);     // 최장 회문의 길이
    int len_cur(0);     // 현재 회문의 길이

    // 전체 문자열을 순회
    for (int i = 0; i < N; i++)
    {
        // 홀수와 짝수 길이의 회문을 찾기 위해 2번씩 반복
        for (int j = 0; j < 2; j++)
        {
            // i를 시작으로 j를 끝으로 하는 가장 긴 회문 찾기
            str_cur = longest_palindrome(str, i, i + j);
            // 현재 회문의 길이 구하기
            len_cur = str_cur.size();

            if (len_cur > len_max) // 현재 회문이 최장 회문보다 더 길면
            {
                len_max = len_cur; // 최장 회문의 길이 갱신
                str_max = str_cur; // 최장 회문의 문자열 갱신
            }
        }
    }

    return str_max;
}

int main()
{
    cout << longest_palindrome_substring("mbababbna") << endl;

    return 0;
}
