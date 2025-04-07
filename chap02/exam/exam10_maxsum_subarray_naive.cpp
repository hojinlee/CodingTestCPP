// O(n^3)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int maxsum_subarray(vector<int>& data) 
{
    // data는 음수를 포함하기 때문에 0보다 작을 수도 있습니다.
    // 초기값을 int가 저장할 수 있는 가장 작은 값으로 설정합니다.
    int ans = INT_MIN; 


    for(int i = 0; i < data.size(); i++) // 합을 구할 시작점입니다.
    {
        for(int j = i; j < data.size(); j++) // 합을 구할 끝점입니다.
        {
            int sum = 0; // 각 부분 배열의 합을 구합니다.    
            for(int k = i; k <= j; k++ ) // i부터 j의 합을 구합니다.
            {
                sum += data[k];        
            }
            
            ans = max(ans, sum); // 가장 큰 값을 정답으로 
        }
    }
    
    return ans;
}

int main()
{
    vector<int> data = {1, -4, 5, -1, -2, 3, 8, -2}; 
    cout << maxsum_subarray(data) << endl; // 13
    return 0;
}