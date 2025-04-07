#include <iostream>
using namespace std;

// 최대공약수(greatest common divisor)
int gcd_iter(int a, int b)
{
    // 이하의 코드가 a가 항상 b보다 크거나 같다고 가정하기에 여기서 체크
    if (a < b)
        swap(a, b);

    while (b > 0)
    {
        a = a % b;
        swap(a, b); // 나눈 수 b를 다음 반복에서 나누어 지는 수로 만든다.
    }

    return a;
}

int main()
{
    cout << gcd_iter(16, 18) << endl; // 16과 18의 최대 공약수 구하기
    return 0;
}
