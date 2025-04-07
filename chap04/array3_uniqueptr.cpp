#include <memory>
using namespace std;

int main()
{
    // unique_ptr로 int 배열을 생성합니다. typename에 int[]로 배열임을 지정합니다.
    unique_ptr<int[]> somePtr(new int[10]);
    // unique_ptr의 get() 함수를 사용하여 raw 포인터를 얻습니다.
    int *pArr = somePtr.get();
    pArr[1] = 4;

    return 0;
}