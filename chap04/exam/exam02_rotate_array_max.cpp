#include <iostream>
#include <vector>
using namespace std;

int rotate_array_max(const vector<int> &nums)
{
    if (nums.size() == 0)
        return -1;                       // 빈 배열이면
    int left(0), right(nums.size() - 1); // 탐색할 영역을 가리키는 인덱스

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // 중간 인덱스를 찾습니다.
        // 어떤 값이 다음 값보다 크면 이 값이 가장 큰 값입니다.
        if (nums[mid] > nums[mid + 1])
            return nums[mid];

        if (nums[left] <= nums[mid]) // 왼쪽이 정렬된 배열일 경우
        {
            left = mid + 1; // 오른쪽 부분 배열에서 검색
        }
        else
        {
            right = mid - 1; // 왼쪽 부분 배열에서 검색
        }
    }

    return nums[0]; // 모든 원소의 값이 같은 경우
}

int main()
{
    cout << rotate_array_max({3, 4, 1, 2}) << endl;
    cout << rotate_array_max({4, 5, 6, 1, 2, 3}) << endl;

    return 0;
}
