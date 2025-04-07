#include <iostream>
using namespace std;

int fibonacci_recur(int n)
{
    if (n <= 2)
        return 1;

    // n-1과 n-2항의 피보나치 수를 더하여 값을 구합니다.
    return fibonacci_recur(n - 1) + fibonacci_recur(n - 2);
}

int main()
{
    cout << fibonacci_recur(10) << endl; // 55

    return 0;
}
