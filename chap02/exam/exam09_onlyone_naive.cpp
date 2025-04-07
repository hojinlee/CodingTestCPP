#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int find_onlyone(vector<int>& nums) 
{
    unordered_map<int,int> map_nums; // 출현 빈도를 맵에 저장
    for(int& num: nums)
    {
        
        map_nums[num]++; // 맵 내에 num이 없다면 1로 설정
    }
    
    for(auto& it: map_nums) // 맵 내 빈도가 1인 경우 찾기
    {
        if(it.second == 1)
            return it.first;
    }

    return 0;
}

int main()
{
    vector<int> data = {1023, -1, 999999, 2, 1023, -1, 999999}; // 2
    cout << find_onlyone(data) << endl;
    return 0;
}