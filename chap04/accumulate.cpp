#include <iostream>
#include <array>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    array<int,2> arr = { 2000000000, 2000000001 };
    long long sum = accumulate(arr.begin(), arr.end(), 0); 
    cout << sum << endl; // -294967295, 오버플로
    
    sum = accumulate(arr.begin(), arr.end(), 0LL);  // 초기화를 0LL로
    cout << sum << endl; // 4000000001, 정상 출력
    
    vector<int> v = { 2, 3, 4 };
    int mul = accumulate(v.begin(), v.end(), 1, multiplies<int>());  
    cout << mul << endl; // 24
    
    return 0;
}