#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 막대 자르기, prices: 각 크기로 잘랐을 때의 가격 목록
int cut_rod(const vector<int> &prices)
{
    const int N = prices.size(); // 막대의 길이

    // dp 테이블, dp[i]는 i크기의 최대 수익
    vector<int> dp(N + 1, 0);

    // 1부터 N크기까지의 최대 수익 구하기
    for (int i = 1; i <= N; ++i)
    {
        // 각 방법 j에 대한 최대 수익을 구하기
        for (int j = 1; j <= i; ++j)
        {
            // j크기의 막대를 사용할 때와 사용하지 않을 때의 최대 수익 비교
            dp[i] = max(prices[j - 1] + dp[i - j], dp[i]);
        }
    }

    return dp[N]; // 테이블의 끝에 있는 최대 수익 반환
}

int main()
{
    cout << cut_rod({2, 3, 5, 10, 11, 12}) << endl;
    return 0;
}
