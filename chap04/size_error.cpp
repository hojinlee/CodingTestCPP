#include <iostream>
#include <vector>
using namespace std;

void test(const vector<int>& v) 
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v1(3); // size = 3 으로 생성
    test(v1);
    vector<int> vErr; // size = 0 으로 생성, size - 1 에서 에러 발생
    test(vErr); // 실행 시간 에러 발생
    return 0;
}