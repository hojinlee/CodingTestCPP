#include <iostream>
using namespace std;

int getFactorial(int n)
{
    // 0!는 1입니다.
    if (n == 0)
        return 1;
    return n * getFactorial(n - 1);
}

int main()
{
    cout << getFactorial(3) << endl; // 실행 결과: 6
    return 0;
}