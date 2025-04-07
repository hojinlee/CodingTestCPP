#include <iostream>
#include <queue> // priority_queue
#include <vector>

using namespace std;

void kthMinStream(vector<int> &data, int k)
{
    priority_queue<int> maxheap; // 최대 힙을 만듭니다.
    vector<int> ret;

    // 스트림을 차례대로 순회합니다.
    for (int i = 0; i < data.size(); i++)
    {
        if (i < k) // 처음 k개를 최대 힙에 넣습니다.
            maxheap.push(data[i]);
        else if (maxheap.top() > data[i])
        {
            // 최대 힙의 가장 큰 값이 현재 값보다 크면
            maxheap.pop();         // 꺼내고
            maxheap.push(data[i]); // 현재 값을 최대 힙에 넣습니다.
        }

        if (i >= k - 1)                   // 최대 힙에 k개의 원소가 있으면
            ret.push_back(maxheap.top()); // 결과에 최대 힙의 값을 추가합니다.
    }

    for (int i : ret)
        cout << i << ", ";
    cout << endl;
}

int main()
{
    vector<int> data = {10, 8, 7, 9, 6};
    kthMinStream(data, 3);

    return 0;
}