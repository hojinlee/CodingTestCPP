#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find_no_redundant(vector<int> &in)
{
    unordered_map<int, int> map_nums;

    // 각 값의 출현 횟수를 맵에 업데이트합니다.
    for (int &i : in)
        map_nums[i]++;

    for (auto it = map_nums.begin(); it != map_nums.end(); it++)
    {
        if (it->second == 1)  // 출현 횟수가 한 번이면
            return it->first; // 중복이 없는 유일한 값입니다.
    }
    return 0;
}

int main()
{
    vector<int> datas = {5, 4, 5, 3, 4, 5, 4};
    cout << find_no_redundant(datas) << endl;

    return 0;
}