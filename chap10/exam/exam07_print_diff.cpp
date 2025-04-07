#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 첫 번째 배열에서 두 번째 배열의 차를 출력
void print_diff(const vector<int>& v1, const vector<int>& v2)
{
    // v2의 값으로 s2를 생성
    unordered_set<int> s2(v2.begin(), v2.end());

    // v1의 모든 원소를 순회하여 차집합 만들기
    for (auto e1: v1)
    {
        if(s2.count(e1) == 0) // s2에 s1의 원소 e1이 없다면 차집합의 원소
            cout << e1 << " ";
    }
}

int main()
{
    print_diff({4, 5, 3, 2}, {4, 3});

    return 0;
}

