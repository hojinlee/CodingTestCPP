#include <iostream>
using namespace std;

void insertArr(int (&arr)[10], int arrSize, int val, int pos)
{
    for(int i = arrSize; i > pos; i--) // 배열의 끝에서 pos 위치로 한 칸씩 이동
    {
        arr[i] = arr[i - 1]; // pos 위치까지 값을 한 칸씩 뒤로 이동
    }
    arr[pos] = val; // pos 위치에 값을 삽입
}

int main() 
{
    int arr[10] = { 1,2,3,4 };  // 1 2 3 4 0 0 0 0 0 0
    insertArr(arr, 4, 10, 2);

    for(int i: arr)
        cout << i << " ";       // 1 2 10 3 4 0 0 0 0 0 

    return 0;
}