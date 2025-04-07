#include <iostream>
#include <vector>
using namespace std;

int binary_search_iter(vector<int> nums, int target)
{
    int left = 0, right(nums.size() - 1);

    while (left <= right)
    {
        // left + right / 2는 스택오버플로의 발생 우려로 (right - left) 사용
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) // 중간 값이 찾는 값이면
            return mid;
        if (nums[mid] < target) // 찾는 값이 중간값보다 크면, 오른쪽을 더 탐색
            left = mid + 1;
        else // 찾는 값이 중간값보다 작으면, 왼쪽을 더 탐색
            right = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 7, 9, 10};
    cout << binary_search_iter(nums, 9) << endl;
    cout << binary_search_iter(nums, 8) << endl;
    return 0;
}