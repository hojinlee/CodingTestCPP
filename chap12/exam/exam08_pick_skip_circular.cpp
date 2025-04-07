#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nums: 선택할 정수 배열
int pick_skip(const vector<int> &nums, const int offset)
{
    const int N = nums.size() - 1; // 원소의 갯수
    if (N == 0)
        return 0; // 원소가 하나도 없으면 0을 반환
    if (N == 1)
        return nums[offset]; // 원소가 하나 뿐이면 첫 번째 원소의 값을 반환

    // 원소 갯수 만큼 dp 테이블을 생성
    vector<int> dp(N, 0);
    dp[0] = nums[offset];                        // 첫 번째 위치에서 최댓값
    dp[1] = max(nums[offset], nums[offset + 1]); // 두 번째 위치에서 때 최댓값

    // 3번째 위치부터 마지막까지 순회
    for (int i = 2; i < N; ++i)
    {
        // 바로 옆 원소의 값과 옆옆 원소의 최댓값 + 현재값을 비교하여 큰 값을 dp[i]에 저장
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + offset]);
    }

    // 마지막 원소의 최댓값을 결과로 반환
    return dp[N - 1];
}

// nums: 선택할 정수 배열
int pick_skip_circular(const vector<int> &nums)
{
    const int N = nums.size(); // 원소의 갯수
    if (N == 0)
        return 0; // 원소가 하나도 없으면 0을 반환
    if (N == 1)
        return nums[0]; // 원소가 하나 뿐이면 첫 번째 원소의 값을 반환

    // 첫 번째 원소를 선택하는 경우와 제외하는 경우에 대해 따로 구해서 그 중 최댓값 반환
    return max(pick_skip(nums, 0), pick_skip(nums, 1));
}

int main()
{
    cout << pick_skip_circular({1, 8, 6, 4, 5}) << endl;

    return 0;
}
