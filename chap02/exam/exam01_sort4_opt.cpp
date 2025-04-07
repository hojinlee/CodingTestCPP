// sort array which includes '0, 1, 2, 3' only
// O(n)
#include <iostream>
#include <vector>
using namespace std;

void sort_0123(vector<int>& data) 
{
    int count[4] = {0, }; // 출현 빈도, 0부터 3까지 4개의 원소만 존재
    
    // data 내의 출현 빈도 세기
    for(int i: data)
    {
        count[i]++; // 발견한 값의 인덱스를 증가
    }

    // 출현 빈도 대로 data 갱신
    int cur = 0; // data 갱신에 사용하는 현재 위치
    for(int i = 0; i < 4; i++)
    {
        fill_n(data.begin()+cur, count[i], i);
        cur += count[i];
    }
}

int main() 
{
    vector<int> data = { 0, 1, 3, 2, 3, 2, 1, 0, 1};
    sort_0123(data);
    for(int i: data)
        cout << i << ", " ; // 0, 0, 1, 1, 1, 2, 2, 3, 3, 
    cout << endl;
    return 0;
}
