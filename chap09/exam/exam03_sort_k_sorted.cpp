#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// k-정렬된 배열을 정렬하기
void sort_k_sorted(vector<int> &arr, int k)
{
    // 최소 힙 생성
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // 첫 k+1개의 원소를 힙에 삽입
    for (int i = 0; i <= k; ++i)
    {
        min_heap.push(arr[i]);
    }

    int index = 0; // 삽입 위치를 위한 인덱스

    // 다음 원소를 힙에 삽입하고, 가장 작은 원소를 꺼내어 배열에 삽입
    for (int i = k + 1; i < arr.size(); ++i)
    {
        arr[index++] = min_heap.top(); // 가장 작은 원소를 배열에 삽입
        min_heap.pop();                // 가장 작은 원소 제거
        min_heap.push(arr[i]);         // 다음 원소 삽입
    }

    // 힙의 모든 원소를 꺼내어 배열에 삽입
    while (!min_heap.empty())
    {
        arr[index++] = min_heap.top(); // 가장 작은 원소를 배열에 삽입
        min_heap.pop();                // 가장 작은 원소 제거
    }
}

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};

    sort_k_sorted(arr, 2);

    for (int num : arr)
        cout << num << " "; // 정렬된 배열 출력

    cout << endl;
    return 0;
}
