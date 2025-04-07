// O(n+m)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> merge_sorted(const vector<int>& data1, const vector<int>& data2) 
{
    vector<int> ans; // 빈 벡터 ans를 만듭니다.

    int i1(0), i2(0); // data1과 data2에 대한 인덱스를 각각 만듭니다.
    
    while(i1 < data1.size() && i2 < data2.size())
    {
        int cur1 = data1[i1];
        int cur2 = data2[i2];

        if( cur1 < cur2)
        {
            ans.push_back(cur1);
            i1++;            
        }
        else
        {
            ans.push_back(cur2);
            i2++;
        }
    }
    // 두 배열 중 남은 배열을 삽입합니다.
    if(i1 < data1.size())
    {
        // data1의 남은 배열을 ans 뒤에 삽입합니다. 
        ans.insert(ans.end(), data1.begin() + i1, data1.end());
    }
    else if(i2 < data2.size())
    {
        // data1의 남은 배열을 ans 뒤에 삽입합니다. 
        ans.insert(ans.end(), data2.begin() + i2, data2.end());
    }
    
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
