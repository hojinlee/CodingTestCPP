// O(n log n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int diff_maxmin(vector<int>& data) 
{
    sort(data.begin(), data.end());  
    // 정렬 후 rbegin(): 가장 큰값, begin(): 가장 작은 값
    return *data.rbegin() - *data.begin(); // *를 쓰는 이유는 iterator()를 반환하기 때문에
}

int main() 
{
    vector<int> data = { 1, 4, 5, 3, 2};
    cout << diff_maxmin(data) << endl; // 4
    return 0;
}
