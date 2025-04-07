// 메모이제이션으로 피보나치 수를 구하는 예제
#include <iostream>

using namespace std;

#define FB_SIZE 100  // dp 배열의 크기
// 피보나치 수를  저장하는 dp 배열을 선언합니다.
int dp[FB_SIZE] = { 0, };  // 배열 전체 항목을 0으로 초기화

int fibonacci_m(int n)
{
    if (n < 2)
       return n;

    // dp에 기존에 계산한 값이 있으면 사용합니다.  
    if (dp[n] > 0) return dp[n];

    return dp[n] = fibonacci_m(n - 1) + fibonacci_m(n - 2);
}

int main()
{
    for (int i = 0; i < 10; i++) // 처음 10개의 피보나치 수열
    {
        cout << fibonacci_m(i) << endl; // 1 1 2 3 5 8 13 21 34 55
    }

  return 0;
}