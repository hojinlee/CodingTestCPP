#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// nums에서 3개의 원소의 합이 target가 되는지 여부
bool triple_sum(const vector<int>& nums, int target)
{
    unordered_map<int, int> table; // nums의 원소값을 키로, 인덱스를 값으로 하는 테이블

    for (int i = 0; i < nums.size(); i++)
    {
        // 테이블에 모든 원소를 쌍으로 값 삽입
        table[nums[i]] = i;
    }

    // nums를 순회하며 2개의 원소를 고릅니다. 항상 i < j, i는 마지막 원소 직전까지만 순회
    for (int i = 0; i < nums.size() - 1; i++)  // i가 마지막 원소까지 순회하면 j가 nums 범위를 벗어남
    {
        // i 다음 원소부터 순회합니다.
        for (int j = i + 1; j < nums.size(); j++) // j는 i다음 원소부터 마지막 원소까지 순회
        {
            // 2개의 원소를 골라서 그 합을 target에서 빼줍니다.
            int remain = target - nums[i] - nums[j];

            // 테이블에서 remain값과 일치하는 값이 있는지 찾습니다.
            if(table.find(remain) != table.end())
            {
                // 현재 고른 i, j와 테이블의 인덱스가 중복이 아니면
                if(table[remain] != i && table[remain] != j)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    cout << triple_sum({1, 5, 2, 3, 4}, 8) << endl;
    cout << triple_sum({1, 5, 2, 3, 4}, 13) << endl;

    return 0;
}
