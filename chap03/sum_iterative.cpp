#include <iostream>
using namespace std;

int sumIter(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++) // 1부터 n까지의
    {
        ans += i; // 합계를 계산
    }
    return ans;
}

int main()
{
    cout << sumIter(10) << endl;
    return 0;
}