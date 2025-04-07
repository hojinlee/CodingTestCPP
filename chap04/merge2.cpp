#include <iostream>
#include <vector>
#include <algorithm> // merge 함수를 포함

using namespace std;
int main()
{
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};
    vector<int> ret;
    // 두 벡터를 병합하여 정렬된 결과를 ret 벡터에 삽입
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(ret, ret.begin()));

    for (auto const &e : ret) // ret 벡터를 출력
        cout << e << ' ';     // 1 2 3 4 5 6

    return 0;
}