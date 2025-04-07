#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 세 정수 벡터의 합집합 출력
void print_union(const vector<int>& v1, const vector<int>& v2, const vector<int>& v3)
{
    // 최종 합집합 결과를 저장하는 v1의 값으로 s1을 생성
    set<int> ans(v1.begin(), v1.end());
    // v2의 값을 결과 세트에 저장, 순서 유지됨
    ans.insert(v2.begin(), v2.end());
    // v3의 값을 결과 세트에 저장, 순서 유지됨
    ans.insert(v3.begin(), v3.end());

    // 합집합을 출력
    for (auto e: ans)
    {
        cout << e << " ";
    }
}

int main()
{
    print_union({4, 5, 3, 2}, {4, 3}, {1, 3, 5});

    return 0;
}

