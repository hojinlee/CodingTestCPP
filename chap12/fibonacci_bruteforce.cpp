#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n < 2) // 0, 1번째 항은 1
        return 1;

    // n-1과 n-2항의 피보나치 수를 더하여 값을 구합니다.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    for (int i = 0; i < 10; i++) // 처음 10개의 피보나치 수열
    {
        cout << fibonacci(i) << endl; // 1 1 2 3 5 8 13 21 34 55
    }

    return 0;
}