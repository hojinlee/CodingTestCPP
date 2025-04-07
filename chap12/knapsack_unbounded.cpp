#include <iostream>
#include <vector>

using namespace std;

// 물건 구조체 정의
struct item
{
    int value;  // 가치
    int weight; // 무게
};

int knapsack(int w, vector<item> items)
{
    const int N = items.size(); // 물건 개수

    // 이전 값을 참조하는 DP계산에서 초깃값으로
    // 패딩을 추가하여 N과 w가 아니라 N + 1과 w + 1 크기를 사용하는 dp 테이블 초기화
    vector<vector<int>> dp(N + 1, vector<int>(w + 1, 0));

    // 물건의 종류에 따라 N번 순회, 패딩을 추가하여 1부터 시작
    for (int i = 1; i <= N; i++) 
    {
        // 담을 수 있는 용량을 W번 순회, 역시 패딩으로 부터 시작
        for (int j = 1; j <= w; j++)
        {
            // 물건의 무게가 더 무거워서 현재 담을 수 있는 용량보다 무거울 때
            if (items[i - 1].weight > j) 
            {
                // 이전 물건을 담았을 때 최댓값을 사용
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // 이전 행 물건을 담았을 때 최댓값과 
                // 이전 행 최댓값에서 현재 물건 무게 만큼 비운 자리에 현재 물건을 담았을 때를 비교
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
                // 윗 코드에서 구한 최댓값과 
                // 현재 행 최댓값에서 현재 물건 무게 만큼 비운 자리에 현재 물건을 담았을 때를 비교
                dp[i][j] = max(dp[i][j], dp[i][j - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    return dp[N][w]; // 최댓값 반환
}

int main()
{
    cout << knapsack(8, {{2, 2}, {6, 3}, {13, 7}}) << endl;
    cout << knapsack(20, {{3, 3}, {14, 5}, {36, 12}}) << endl;

    return 0;
}