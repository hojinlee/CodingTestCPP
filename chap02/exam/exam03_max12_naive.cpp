// 가장 큰 수와 두번째로 큰 수를 찾아서 더하기
// O(n log n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum_max_12(vector<int>& data) 
{
    sort(data.begin(), data.end());  

    // rbegin에서 1을 더하면 맨뒤에서 바로 앞 원소입니다.
    return *data.rbegin() + *(data.rbegin()+1); 
}

int main() 
{
    vector<int> data = { 1, 4, 5, 3, 2};
    cout << sum_max_12(data) << endl; // 9
    return 0;
}
