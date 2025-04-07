#include <iostream>
#include <vector>
using namespace std;

int sum_array_iter(vector<int> nums)
{
    int ans = 0;
    for(int i: nums)
    {
        ans += i; // 배열의 각 원소의 값을 더합니다
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 7, 9, 10};
    cout << sum_array_iter(nums) << endl; 
    return 0;
}
