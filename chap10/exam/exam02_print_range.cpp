#include <iostream>
#include <map>
#include <set>
using namespace std;

void print_range(const map<int, string> &map_in, int low, int high)
{
    set<string> students; // 중복없이 정렬하기 위해 set을 사용

    // 특정 범위의 값만 순회
    for (auto it = map_in.lower_bound(low); it != map_in.upper_bound(high); it++)
    {
        students.insert(it->second); // 조건을 만족하는 값을 students에 추가
    }

    for (auto it : students)
    {
        // 결과 출력
        cout << it << " ";
    }
}

int main()
{
    map<int, string> scores = {{91, "tom"},
                               {81, "jimmy"},
                               {92, "tom"},
                               {94, "peter"}};
    print_range(scores, 91, 94);

    return 0;
}
