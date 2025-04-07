// O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 현재 인덱스의 최대 부분 배열 합 = 이전 인덱스가 가질 수 있는 최대 부분 배열 합 + 현재 인덱스의 값
int maxsum_subarray(vector<int> data) 
{
    int ans = data[0]; // 정답을 data[0]의 값으로 초기화

    for(int i = 1; i < data.size(); i++)
    {
        // 이전 부분 배열 합을 포함한 것과 아닌 것 중에 최댓값 찾기
        data[i] = max(data[i] + data[i-1], data[i]); 
        
        ans = max(ans, data[i]); 
    }
    
    return ans;
}

int main()
{
    vector<int> data = {1, -4, 5, -1, -2, 3, 8, -2}; 
    cout << maxsum_subarray(data) << endl; // 13
    return 0;
}
