#include <iostream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;

int main() 
{
    int arr1[5];
    iota(begin(arr1), end(arr1), -3); // 배열에 -3부터 채우기
    for(auto& i: arr1)
        cout << i << " "; // -3 -2 -1 0 1
    cout << endl; 
    
    array<int,5> arr2;
    iota(arr2.begin(), arr2.end(), -3); // array에 -3부터 채우기
    for(auto& i: arr2)
        cout << i << " "; // -3 -2 -1 0 1
    cout << endl; 
    
    vector<int> v(5);
    iota(v.begin(), v.end(), -3); // vector에 -3부터 채우기
    for(auto& i: v)
        cout << i << " "; // -3 -2 -1 0 1
    cout << endl; 

    iota(v.rbegin(), v.rend(), -4); // vector의 뒤에서 앞으로 -4부터 채우기
    for(auto& i: v)
        cout << i << " "; // 0 -1 -2 -3 -4
    cout << endl; 
        
    return 0;
}

