#include <iostream>
#include <vector>
using namespace std;

int binary_search_recur(vector<int> nums, int target, int left, int right)
{
    if(left > right) // 종료 조건, 왼쪽 인덱스가 오른쪽보다 큰 것은 비정상
        return -1;
    
    // left + right / 2는 스택오버플로의 발생 우려로 (right - left) 사용
    int mid = left + (right - left) / 2; 
    if(nums[mid] == target) // 중간 값이 찾는 값이면
        return mid;
    if(nums[mid] < target) // 찾는 값이 중간값보다 크면, 오른쪽을 더 탐색
        return binary_search_recur(nums, target, mid + 1, right);
    else                   // 찾는 값이 중간값보다 작으면, 왼쪽을 더 탐색
        return binary_search_recur(nums, target, left, mid - 1);
}
        
int main()
{
    vector<int> nums = {1, 3, 7, 9, 10};
    cout << binary_search_recur(nums, 9, 0, nums.size() - 1) << endl; 
    cout << binary_search_recur(nums, 8, 0, nums.size() - 1) << endl; 
    return 0;
}
