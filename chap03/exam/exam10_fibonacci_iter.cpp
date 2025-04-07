#include <iostream>
#include <vector>
using namespace std;

int fibonacci_iter(int n)
{
    if (n <= 2)
        return 1;

    vector<int> prev(2, 1); // prev[0]: n-2, prev[1]: n-1
    
    for(int i = 2; i < n; i++)
    {
        // (n-2)과 (n-1)을 더해서 n-2에 저장합니다. n-1은 다음 반복에 n-2로 변경됩니다.
        prev[0] += prev[1]; // prev[0]에 n을 저장하고
        swap(prev[0], prev[1]); // n과 n-1 위치를 바꿉니다. (n-1, n) -> (n-2, n-1)
    }
    // n-1과 n-2항의 피보나치 수를 더하여 값을 구합니다.
    return prev[1];
}

int main()
{
    cout << fibonacci_iter(10) << endl; // 55

    return 0;
}
