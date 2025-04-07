#include <iostream>
using namespace std;

int sumRecur(int n, int i, int sum)
{
    if (i > n)
        return sum;                     // i > n 종료 조건
    return sumRecur(n, i + 1, sum + i); // i를 증가하여 꼬리 재귀 호출
}

int main()
{
    cout << sumRecur(10, 1, 0) << endl;
    return 0;
}