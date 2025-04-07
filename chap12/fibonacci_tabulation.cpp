#include <iostream>

using namespace std;

// 태뷸레이션으로 피보나치 수를 구하는 예제

#define FB_SIZE 100 // dp 배열의 크기
// 피보나치 수를  저장하는 dp 배열을 선언합니다.
int dp[FB_SIZE] = {
    0,
};

// 정적 변수 __를 초기화하는 과정에서 피보나치 수를 계산하는 람다 함수를 호출합니다.
static auto __ = []()
{
    dp[0] = 0; // dp[0]은 피보나치 수 0항의 값을 의미합니다.
    dp[1] = 1;

    for (int i = 2; i < FB_SIZE; i++) // 2항부터 배열 크기까지 계산
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return 0;
}();

int fibonacci_t(int n) // 미리 계산해서 dp배열에서 n항의 값만 반환. O(1)시간 소요
{
    return dp[n];
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << fibonacci_t(i) << endl; // 1 1 2 3 5 8 13 21 34 55
    }

    return 0;
}
