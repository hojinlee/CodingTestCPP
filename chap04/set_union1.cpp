#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = { 1, 2, 10 };
    vector<int> v2 = { 2, 3, 4 };
    vector<int> ret;

    int i1(0), i2(0); // 각 벡터의 현재 인덱스, 0에서 부터 시작
    while(i1 < v1.size() && i2 < v2.size())
    {
        if(v1[i1] < v2[i2])
        {
            ret.push_back(v1[i1++]); 
        }
        else if(v1[i1] == v2[i2]) // 중복 값이 있으면
        {
            i1++;   // v1의 인덱스만 증가
        }
        else // 중복 값이 아니면
        {
            ret.push_back(v2[i2++]); // v2의 값을 삽입해서 병합
        }
    }

    while(i1 < v1.size()) // v1 벡터에서 처리하지 못한 값들을 처리
        ret.push_back(v1[i1++]); // v1의 값을 삽입해서 병합

    while(i2 < v2.size()) // v2 벡터에서 처리하지 못한 값들을 처리
        ret.push_back(v2[i2++]); // v2의 값을 삽입해서 병합

    for (auto const& e : ret)
        cout << e << ' '; // 1 2 3 4 10

    return 0;
}