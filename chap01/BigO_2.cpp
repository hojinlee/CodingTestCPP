#include <iostream>
using namespace std;
 
int sumAll(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    { 
        sum += i;
        sum += n;
    } 

    return sum;
}
 
int main() 
{
    cout << sumAll(100) << endl; // 5050
    return 0;
}