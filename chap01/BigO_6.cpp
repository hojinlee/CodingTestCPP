#include <iostream>
#include <vector>
using namespace std;

int sumAll6(int n, int k)
{
    vector<int> buf((n + 1) * (n + 1), 1);
    for (int i = 0; i < k; i++)
    {
        buf[i * n] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 인접한 이전 행과 열의 값을 더합니다.
            buf[(n + 1) * i + j] = buf[(n + 1) * (i - 1) + j] + buf[(n + 1) * i + j - 1];
        }
    }

    return buf[n * n];
}

int main()
{
    cout << sumAll6(10, 3) << endl; // 10
    return 0;
}