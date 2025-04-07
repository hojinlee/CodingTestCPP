#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 최장 공퉁 부분 문자열 구하기
string longest_common_substring(const string &str1, const string &str2)
{
    const int M = str1.length();
    const int N = str2.length();
    // dp 테이블 생성
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    int max_len = 0; // 최장 부문 문자열의 길이
    int end = 0;     // 문자열 출력을 위해 인덱스가 필요

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << i << "," << j << endl;
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                    end = i;
                    cout << end << endl;
                }
            }
        }
    }
    return str1.substr(end - max_len, max_len);
}

int main()
{
    // cout << longest_common_substring("abcdeg", "bdefgh") << endl;
    cout << longest_common_substring("abc", "aabc") << endl;
    return 0;
}
