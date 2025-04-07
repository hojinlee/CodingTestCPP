#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 두 정수 벡터의 교집합 출력
void print_intersection(const vector<int>& v1, const vector<int>& v2)
{
    // 순서 상관없이 중복없이 빠르게 저장하기 위해 각 벡터를 unordered_set으로 변환
    unordered_set<int> s1(v1.begin(), v1.end());
    unordered_set<int> s2(v2.begin(), v2.end());

    // 크기가 더 작은 집합을 s1으로 바꾸면 바로 다음 for문의 순회 횟수를 줄일 수 있습니다.
    if(s1.size() > s2.size())
        swap(s1, s2);

    // 첫 번째 세트의 모든 원소를 순회
    for(auto e1: s1)
    {
        if(s2.count(e1)) // 첫 번째 세트의 원소가 두 번째 세트에 존재 한다면
            cout << e1 << " "; // 그 값을 출력
    }
}

int main()
{
    print_intersection({5, 4, 5, 3, 2}, {4, 3, 4});

    return 0;
}

