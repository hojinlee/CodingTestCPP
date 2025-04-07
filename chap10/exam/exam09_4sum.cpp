#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// nums에서 4개의 원소의 합이 target가 되는지 여부
bool four_sum(const vector<int>& nums, int target)
{
    // 2 원소의 합을 키로, 이 합을 만들 수 있는 원소 조합의 인덱스를 세트로
    unordered_map<int, unordered_set<int>> table;

    // nums를 순회하며 2개의 원소를 고릅니다. 항상 i < j, i는 마지막 원소 직전까지만 순회
    for (int i = 0; i < nums.size() - 1; i++)  // i가 마지막 원소까지 순회하면 j가 nums 범위를 벗어남
    {
        // i 다음 원소부터 순회합니다.
        for (int j = i + 1; j < nums.size(); j++) // j는 i다음 원소부터 마지막 원소까지 순회
        {
            int sum2 = nums[i] + nums[j]; // i와 j의 합
            int remain = target - sum2; // 2개 원소 합을 target에서 빼주기

            auto remain_find = table.find(remain);
            // 테이블에서 remain값과 일치하는 값이 있는지 찾습니다.
            if( remain_find != table.end())
            {
                auto& subtable = remain_find->second; // 2 원소의 합에 해당하는 하위 테이블

                // 현재 고른 i, j와 sum2를 만든 원소가 중복이 아니라면
                if(subtable.find(i) == subtable.end() &&
                subtable.find(j) == subtable.end())
                {
                    return true;
                }
            }

            table[sum2].insert(i); // 첫 번째 원소 삽입
            table[sum2].insert(j); // 두 번째 원소 삽입
        }
    }

    return false;
}

int main()
{
    cout << four_sum({1, 5, 2, 3, 4, 7}, 11) << endl;
    cout << four_sum({1, 5, 2, 3, 4, 7}, 22) << endl;
    cout << four_sum({6, 7, 1, 4, 2, 3}, 10) << endl;
    cout << four_sum({1, 4, 2, 3, 6, 7}, 10) << endl;
    cout << four_sum({1, 4, 6, 2, 3}, 15) << endl;
    return 0;
}

