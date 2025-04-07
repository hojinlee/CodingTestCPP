#include <iostream>
using namespace std;

// 최대공약수(greatest common divisor)
int gcd_recur(int a, int b) 
{
    int r = a % b;
    if(r == 0) return b; 
    return gcd_recur(b, r); 
}

int main()
{
    cout << gcd_recur(16, 18) << endl; // 16과 18의 최대 공약수 구하기
    return 0;
}
