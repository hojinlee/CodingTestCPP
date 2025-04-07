// O(n), O(k)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

void rotate_array(vector<int>& nums, int k) {
    const int N = nums.size();
    vector<int> temp(k, 0); // 회전할 크기인 k만큼의 공간을 할당
    for (int i = 0; i < k; i++) 
        temp[i] = nums[i]; // 이동하여 뒤로 붙일 데이터를 임시 공간에 복사
    
    for (int i = k; i < N; i++)  
        nums[i - k] = nums[i]; // k만큼 왼쪽으로 이동
    
    for (int i = 0; i < k; i++) 
        nums[N - k + i] = temp[i];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6}; 
    
    rotate_array(nums, 2);

    for(int i: nums)
        cout << i << ',';
    cout << endl;

    return 0;
}
