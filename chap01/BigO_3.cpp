#include <iostream>
#include <vector>
using namespace std;

int sumAll3(int n, int k)
{
    vector<int> buf(n+k+1, 0);

    for(int i=1; i<=n+k; i++)
    { 
        buf[i] = buf[i-1] + i;
    } 

    return buf[n+k];
}

int main() 
{
    cout << sumAll3(100, 50) << endl; //11325
    return 0;
}