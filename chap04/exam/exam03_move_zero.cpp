#include <iostream>
#include <vector>
using namespace std;

void move_zero(vector<int>& nums) 
{
    int place = nums.size() - 1; // 0이 아닌 수를 옮길 위치
    for(int i = place; i >= 0; i--)
    {
        if(nums[i]) // 0이 아닌 수면
            //현재 수를 place로 옮기고 place를 한 칸 왼쪽으로 올김
            swap(nums[i], nums[place--]);
    }
}

int main()
{
    vector<int> nums = {1, 0, 2, 0, 0, 3, 0, 4};
    
    move_zero(nums);
    for(int i: nums)
        cout << i << ",";
    cout << endl;
    
    return 0;
}