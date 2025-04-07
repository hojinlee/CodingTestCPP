#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 긴 회문 부분 시퀀스의 길이를 동적 계획법으로 찾는 함수
int longest_palindrome_subseq(const string &str)
{
    const int N = str.size(); // 입력 문자열 길이
    // 문자열 길이 크기의 2차원 dp 테이블 생성
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 길이 1인 부분 문자열은 모두 회문
    for (int i = 0; i < N; ++i)
        dp[i][i] = 1; // 회문의 길이 1로 설정

    // 길이 2인 시퀀스부터 N길이까지 순회
    for (int len = 2; len <= N; ++len)
    {
        // 시작점은 0부터 목표 길이까지 순회
        for (int i = 0; i <= N - len; ++i)
        {
            int j = i + len - 1;  // j는 시퀀스의 끝
            if (str[i] == str[j]) // 두 문자가 같으면 회문이 됨
            {
                // i와 j사이 부분 시퀀스 회문 최대 길이에 2를 더하기
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                // 두 문자 중 하나를 제외한 최대 길이 중 큰 값을 현재값으로 설정
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // 최장 길이는 모든 문자를 포함하는 부분 시퀀스에 전달됨
    return dp[0][N - 1];
}

int main()
{
    cout << longest_palindrome_subseq("cbacbdccc") << endl;

    return 0;
}
