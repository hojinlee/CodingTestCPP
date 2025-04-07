#include <iostream>
#include <vector>
using namespace std;

int count_stairs(int n)
{
    // 각 계단별 방법의 수를 저장하기 위한 dp 테이블
    // 1-based로 만들기 위해 1을 더함
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{

    cout << count_stairs(5) << endl;

    return 0;
}
