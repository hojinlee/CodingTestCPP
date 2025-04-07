#include <iostream>
#include <vector>
using namespace std;

// 가장 긴 회문 부분 문자열을 동적 계획법으로 찾는 함수
string longest_palindrome_substring_dp(string str)
{
    const int N = str.size(); // 입력 문자열의 길이
    if (N <= 1)               // 경계 조건, 력 문자열의 길이가 1 이하인 경우
        return str;           // 문자열 그래로 반환

    bool dp[N][N]; // dp[i][j]는 부분 문자열이 회문인지 여부

    // 길이 1인 부분 문자열은 모두 회문
    for (int i = 0; i < N; i++)
        dp[i][i] = true;

    string str_cur("");         // 현재 부분 문자열
    int len_max(0), len_cur(0); // 가장 긴 회문 길이와 현재 회문 길이
    int start(0), end(0);       // 회문의 시작과 끝 인덱스

    // j는 비교할 끝 위치, j는 1부터 시작해서 문자열 끝까지 순회
    for (int j = 1; j < N; j++)
    {
        // i는 회문을 비교할 시작 위치, i는 j바로 앞에서 부터 문자열 시작까지 순회
        for (int i = j - 1; i >= 0; i--)
        {
            if (j == i + 1)                    // 길이가 2인 문자열은
                dp[i][j] = (str[i] == str[j]); // 두 문자가 같으면 회문
            else                               // 길이가 2이상은 양 끝 문자가 같은지와 이전 dp가 회문인지를 비교
                // 오른쪽에서 왼쪽으로 가니 이전 dp는 dp[i + 1][j - 1]임
                dp[i][j] = (str[i] == str[j]) && dp[i + 1][j - 1];

            len_cur = j - i + 1; // 현재 부분 문자열의 길이 계산

            // 현재 부분 문자열이 회문이고 길이가 이전 최대 길이보다 길면
            if (dp[i][j] && len_cur > len_max)
            {
                len_max = len_cur; // 최댓값 갱신
                start = i;         // 시작점 갱신
                end = j;           // 끝점 갱신
            }
        }
    }

    // 가장 긴 회문 부분 문자열 반환
    return str.substr(start, end - start + 1);
}

int main()
{
    cout << longest_palindrome_substring_dp("mbababbna") << endl;
    cout << longest_palindrome_substring_dp("abaabaaba") << endl;

    return 0;
}
