#include <iostream>
using namespace std;

int getFactorialTail(int n, int ans) // 기존 계산 결과를 전달하는 인자가 하나 추가됨
{
    if (n == 1)
        return ans;
    return getFactorialTail(n - 1, n * ans); // 이전 계산 결과를 추가함
}

int main()
{
    cout << getFactorialTail(3, 1) << endl;
    return 0;
}