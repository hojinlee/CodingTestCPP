// 가장 큰 수와 두번째로 큰 수를 찾아서 더하기
// O(n)
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int sum_max_12(vector<int>& data) 
{
    // max1은 항상 max2보다 큽니다.
    int max1 = data[0];
    int max2 = INT_MIN;
    
    for(int i = 1; i < data.size(); i++)
    {
        int cur = data[i];
        if(cur > max1)
        {
            // max1은 항상 max2보다 커서 max1이 바뀌면 이전 max1이 새로운 max2가 됩니다.
            max2 = max1; 
            max1 = cur;            
        }
        else if(cur > max2) // 현재값이 max1보다 작지만 max2보단 큰 경우
        {
            max2 = cur;
        }
    }

    return max1 + max2; 
}

int main() 
{
    vector<int> data = { 1, 4, 5, 3, 2};
    cout << sum_max_12(data) << endl; // 9
    return 0;
}