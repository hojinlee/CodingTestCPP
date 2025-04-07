#include <iostream>
#include <vector>
using namespace std;

// coins: 동전의 종류, amount: 만들려는 거스름돈 금액, 동전의 개수를 반환
int coin_amount(const vector<int> &coins, const int amount)
{
    // 거스름돈 크기 만큼의 dp 테이블 생성, 거스름돈 금액으로 초기화
    vector<int> dp(amount + 1, amount + 1);

    // 0원을 만드는 데 필요한 동전 개수는 0개
    dp[0] = 0;

    // 1원 부터 amount원 까지 만드는 데 필요한 동전의 최소 개수 구하기
    for (int i = 1; i <= amount; i++)
    {
        // i원을 만든는데 필요한 동전의 최소 개수 구하기
        for (int coin : coins)
        {
            // 동전의 금액이 i원보다 작거나 같을 때
            if (i >= coin)
            {
                // dp[i - coin]:  i금액에서 현재 동전 금액 만큼을 뺀 개수
                // + 1: 현재 동전 개수인 1을 더하기
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
            cout << dp[i] << " ";
        }
        cout << endl;
    }

    if (dp[amount] > amount) // 주어진 동전으로 amount만큼의 거스름돈을 만들 수 없을 때
        dp[amount] = -1;     // 동전의 최소 개수를 -1로 변경

    return dp[amount]; // 동전의 최소 개수 반환
}

int main()
{
    cout << coin_amount({1, 2, 5}, 8) << endl;

    return 0;
}
