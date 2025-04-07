#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // 두 개의 벡터를 생성하고 초기값으로 초기화합니다.
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};
    vector<int> ret; // 결과 벡터

    int i1(0), i2(0); // 각 벡터의 현재 인덱스, 0부터 시작
    while (i1 < v1.size() && i2 < v2.size())
    {
        if (v1[i1] < v2[i2]) // v1의 원소가 v2의 원소보다 작은 경우
        {
            ret.push_back(v1[i1++]); // v1의 원소를 ret에 추가하고 i1을 증가시킴
        }
        else // v2의 원소가 v1의 원소보다 작은 경우
        {
            ret.push_back(v2[i2++]); // v2의 원소를 ret에 추가하고 i2를 증가시킴
        }
    }

    while (i1 < v1.size()) // v1의 남은 원소를 ret에 추가
        ret.push_back(v1[i1++]);

    while (i2 < v2.size()) // v2의 남은 원소를 ret에 추가
        ret.push_back(v2[i2++]);

    for (auto const &e : ret) // 결과 벡터 ret를 출력
        cout << e << ' ';     // 1 2 3 4 5 6

    return 0;
}