#include <iostream>
#include <vector>
using namespace std;

int sum_array_recur(vector<int> nums, int i = 0)
{
    if(i == nums.size())
        return 0;
    
    return nums[i] + sum_array_recur(nums, ++i);
}

int main()
{
    vector<int> nums = {1, 3, 7, 9, 10};
    cout << sum_array_recur(nums) << endl; 
    return 0;
}
