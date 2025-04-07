// O(n+m log n+m)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> merge_sorted(const vector<int>& data1, const vector<int>& data2) 
{
    vector<int> ans(data1); // data1을 복사하여 ans를 생성합니다.
    // ans의 뒤에 data2를 삽입합니다.
    ans.insert(ans.end(), data2.begin(), data2.end());
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() 
{
    vector<int> data1 = { 1, 2, 4, 5, 8};
    vector<int> data2 = { 3, 6, 9, 10, 11};

    vector<int> ans = merge_sorted(data1, data2);
    for(int i: ans)
    {
        cout << i << ", "; // 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 
    }
    cout << endl;

    return 0;
}
