#include <iostream>
using namespace std;

int power_tail(int x, int n, int ans) // x의 n승
{
    // 종료 조건, x의 0승은 1입니다. 
    // 종료 조건을 1로 하면 x의 0승을 계산 못하기에 0을 종료 조건으로 합니다.
    if(n == 0) return ans; 
    return power_tail(x, n - 1, x * ans);
}

int main()
{
    cout << power_tail(3, 4, 1) << endl; // 3의 4승 구하기
    return 0;
}
