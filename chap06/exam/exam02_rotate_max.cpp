#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void rotate_max(deque<int> nums)
{
    int max_value = *max_element(nums.begin(), nums.end());

    int cnt = 0;
    while (nums.back() != max_value)
    {
        cnt++;                        // 회전 횟수 증가
        nums.push_front(nums.back()); // 앞으로 넣어서 순서 뒤집힘
        nums.pop_back();
    }

    for (int n : nums)
        cout << n << " "; // 덱의 원소를 차례대로 출력
    cout << endl;
    cout << cnt << endl;
}

int main()
{
    rotate_max({2, 7, 6, 4, 3});
    return 0;
}