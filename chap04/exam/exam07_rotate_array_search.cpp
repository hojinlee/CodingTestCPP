#include <iostream>
#include <vector>
using namespace std;

int rotate_array_search(const vector<int>& nums, int target) 
{
    if(nums.size() == 0) return -1; // 빈 배열이면
    int left(0), right(nums.size() - 1);// 탐색할 영역을 가리키는 인덱스

    while(left <= right)
    {
        int mid = left + (right - left) / 2; // 중간 인덱스를 찾습니다.
        if(nums[mid] == target) return mid; // 발견

        if(nums[left] <= nums[mid]) // 왼쪽이 정렬된 배열일 경우
        {
            if(nums[left] <= target && target < nums[mid])
                right = mid - 1; // 왼쪽 부분 배열에서 검색
            else
                left = mid + 1; // 오른쪽 부분 배열에서 검색
        }
        else // 오른쪽이 정렬된 배열일 경우  
        {
            if(nums[mid] < target && target <= nums[right])
                left = mid + 1; // 오른쪽 부분 배열에서 검색
            else
                right = mid - 1; // 왼쪽 부분 배열에서 검색
        }

    }
    
    return -1; // 발견하지 못했을 경우
}

int main()
{
    vector<int> nums = {3, 4, 1, 2}; 
    
    for(int i = 0; i < 5; i++)
        cout << rotate_array_search(nums, i) << ",";
    cout << endl;
    cout << rotate_array_search({}, 0) << ",";
    
    return 0;
}


