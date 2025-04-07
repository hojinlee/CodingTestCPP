#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median_2sorted(const vector<int> &nums1, const vector<int> &nums2)
{
    int i(0), j(0), ans(0);

    // 중간값의 인덱스를 구합니다. 6개와 7개의 중간값 인덱스 3
    int mid = (nums1.size() + nums2.size()) / 2;

    for (int k = 0; k <= mid; k++)
    {
        if (i == nums1.size()) // nums1을 다 순회했으면 j를 증가
        {
            ans = nums2[j++];
            continue;
        }

        if (j == nums2.size()) // nums2을 다 순회했으면 j를 증가
        {
            ans = nums1[i++];
            continue;
        }

        // 작은 값의 인덱스로 값을 갱신하고 인덱스를 증가합니다.
        if (nums1[i] < nums2[j])
        {
            ans = nums1[i++];
        }
        else
        {
            ans = nums2[j++];
        }
    }

    return ans;
}

int main()
{
    cout << median_2sorted({1, 3, 6}, {2, 4, 5, 7}) << endl;
    cout << median_2sorted({1, 3, 6}, {2, 4, 5}) << endl;
    cout << median_2sorted({1, 2}, {3, 4, 5, 6, 7}) << endl;
    cout << median_2sorted({1, 2}, {3, 4, 5, 6}) << endl;
    cout << median_2sorted({1, 2, 3, 4}, {}) << endl;
    cout << median_2sorted({}, {1, 2, 4}) << endl;

    return 0;
}
