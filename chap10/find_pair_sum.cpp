// O(n), O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 합이 k가 되는 한 쌍의 정숫값을 찾아 그 인덱스의 합을 반환
int find_pair_sum(const vector<int> &nums, int k)
{
    // nums의 값을 키로, 인덱스를 값으로 하는 해시 테이블
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
    {
        int num_pair = k - nums[i]; // 합에서 현재 값을 빼면 찾으려는 값, 쌍이 되는 값

        // 쌍이 되는 값이 해시 테이블에 있다면
        if (hash.find(num_pair) != hash.end())
        {
            cout << i << ", " << hash[num_pair] << endl;
            return i + hash[num_pair]; // 쌍을 찾음, 두 인덱스의 합을 반환
        }

        hash[nums[i]] = i; // 현재 값의 인덱스를 해시 테이블에 추가
    }

    return -1;
}

int main()
{
    cout << find_pair_sum({6, 2, 3, 5, 1}, 4) << endl;          // 2, 4
    cout << find_pair_sum({1, -8, 2, -4, 3, 6, 7}, -4) << endl; // 정답이 없음

    return 0;
}