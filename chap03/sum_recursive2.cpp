#include <iostream>
using namespace std;

int sumRecur2(int n)
{
    if (n < 1)
        return 0;
    return sumRecur2(n - 1);
}

int main()
{
    cout << sumRecur2(10) << endl;
    return 0;
}