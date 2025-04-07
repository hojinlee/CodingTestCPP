#include <iostream>
#include <set>
using namespace std;

// 한 집합이 다른 집합의 부분집합인지 여부
bool is_subset(set<int> s1, set<int> s2)
{
    // 항상 s1보다 s2가 크다고 가정합니다.
    if(s1.size() > s2.size()) // s1이 더 크다면
        swap(s1, s2); // s2가 크도록 만듭니다.

    // s1의 모든 원소를 순회
    for(auto e1: s1)
    {
        if(s2.count(e1) == 0) // s1의 원소가 하나라도 s2에 없다면
            return false;  // s1는 s2의 부분집합이 될 수 없다.
    }
    return true;
}

int main()
{
    cout << is_subset({1, 5, 2, 3, 4, 7}, {1, 4, 2}) << endl;
    cout << is_subset({1, 5, 2, 3, 4, 7}, {1, 4, 6}) << endl;
    cout << is_subset({1, 4, 2}, {1, 4, 2}) << endl;
    cout << is_subset({1, 4, 2}, {1, 4, 3}) << endl;
    cout << is_subset({1, 4, 2}, {1, 4, 2, 3}) << endl;

    return 0;
}


