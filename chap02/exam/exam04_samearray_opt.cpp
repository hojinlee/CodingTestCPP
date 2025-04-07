#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool same_array(vector<int>& data1, vector<int>& data2) 
{
    // 각 값의 출현 빈도를 비교하는 데 사용합니다.
    unordered_map<int, int> hit;

    for(int i: data1)
    {
        hit[i]++; // 출현 빈도를 더합니다.
    }

    for(int i: data2)
    {
        hit[i]--; // 출현 빈도를 뻅니다.
    }

    for(auto it: hit)
    {
        // 출현 빈도가 0이 아니라면 다른 원소가 존재함을 의미합니다.
        if( it.second != 0)
            return false;
    }

    return true;
}

int main() 
{
    vector<int> data1 = { 1, 4, 5, 3, 2};
    vector<int> data2 = { 2, 5, 4, 3, 1};
    vector<int> data3 = { 3, 7, 1, 4, 5};
    cout << same_array(data1, data2) << endl; // 1
    cout << same_array(data1, data3) << endl; // 0
    return 0;
}
