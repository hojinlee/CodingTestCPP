#include <memory>
using namespace std;

int main()
{
    // 스마트 포인터 somePtr를 선언하고, 길이가 10인 int 배열을 동적으로 할당합니다
    shared_ptr<int> somePtr(new int[10], default_delete<int[]>());

    // 스마트 포인터에서 원본 배열에 대한 포인터를 얻어와 pArr에 할당합니다.
    int *pArr = somePtr.get();
    // 배열의 두 번째 원소에 값 4를 할당
    pArr[1] = 4;

    return 0;
}