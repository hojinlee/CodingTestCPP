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
    // 패딩을 추가하여 N과 w가 아니라 N + 1과 w + 1 크기를 사용하는 dp 테이블 초기화
    vector<vector<int>> dp(N + 1, vector<int>(w + 1, 0));

    // 물건들을 순회
    for (int i = 1; i <= N; i++)
    {
        // 담을 수 있는 용량을 순회
        for (int j = 1; j <= w; j++)
        {
            // 물건의 무게가 더 무거워서 현재 담을 수 있는 용량보다 무거울 때
            if (items[i - 1].weight > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // 현재 물건을 담는 경우와 담지 않는 경우 중 최대 가치를 선택
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    return dp[N][w]; // 최종 결과 반환
}

int main()
{
    // 테스트 케이스 실행
    cout << knapsack(9, {{6, 3}, {9, 4}, {17, 9}}) << endl;
    cout << knapsack(9, {{4, 4}, {6, 5}, {8, 6}}) << endl;

    return 0; // 프로그램 종료
}