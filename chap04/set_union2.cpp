#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    vector<int> v1 = { 1, 2, 10 };
    vector<int> v2 = { 2, 3, 4 };
    vector<int> ret;

    // set_union()을 사용하여 v1과 v2의 합집합을 구해서 ret에 저장합니다.
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::inserter(ret, ret.begin()));
    
    for (auto const& e : ret)
        cout << e << ' '; // 1 2 3 4 10

    return 0;
}