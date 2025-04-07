// O(n), O(1)
#include <iostream>
#include <vector>
using namespace std;

// 가장 긴 교대 부분 시퀀스의 길이를 반환
int longest_alternate(const vector<int> &nums)
{
    const int N = nums.size();
    if (N == 0)
        return 0; // 입력 크기가 0이면

    int ans = 1;
    int cur = 1; // 현재 부분 배열의 길이, 최소 문자 하나의 길이인 1을 기본값으로
    for (int i = 1; i < N; i++)
    {
        if (nums[i - 1] * nums[i] < 0) // 두 수의 부호가 다를 때
        {
            cur++; // 현재 부분 배열의 길이 증가
            ans = max(ans, cur);
        }
        else
        {
            cur = 1; // 두 수의 부호가 같을 때 현재 길이를 1로 초기화
        }
    }

    return ans;
}

int main()
{
    cout << longest_alternate({}) << endl;
    cout << longest_alternate({1}) << endl;
    cout << longest_alternate({11, 10, 12, 15, 1, 3, 2, 4}) << endl;

    return 0;
}
