// O(n^2)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum_combination(const vector<int>& data) 
{
    int ans = 0;
    
    // 무차별 대입봅으로 조합을 구합니다.
    // 마지막 원소를 포함하면 last-last같은 조합이 나오므로 제외합니다.
    for(int i = 0; i < data.size() -1; i++) 
    {
        for(int j = i + 1; j < data.size(); j++) 
        {
            ans += data[i] + data[j];
        }
    }
    
    return ans;
}

int main() 
{
    vector<int> data = { 5, 8, 2, 1, 4 };
    
    cout << sum_combination(data) << endl; // 80

    return 0;
}

