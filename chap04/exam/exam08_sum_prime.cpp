#include <iostream>
#include <vector>
using namespace std;

// 2~n의 모든 소수의 합
int sum_prime(int n)
{
    int ans(0);
    // 에라토스테네스의 체(망, sieve) 알고리즘을 사용
    vector<bool> sieve(n + 1, false); // n까지 비교를 위해 +1, 소수가 아니면 true

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue; // 이미 소수가 아닌 것으로 걸려진 경우

        ans += i;                           // 소수로 추가
        for (int j = i + i; j <= n; j += i) // i의 배수를 모두 소수가 아닌 것으로 체크
            sieve[j] = true;
    }

    return ans;
}

int main()
{
    cout << sum_prime(13) << endl;     // 41
    cout << sum_prime(1) << endl;      // 0
    cout << sum_prime(20) << endl;     // 77
    cout << sum_prime(100000) << endl; // 77

    return 0;
}
