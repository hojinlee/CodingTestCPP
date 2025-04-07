#include <iostream>
#include <queue> // priority_queue
#include <vector>

using namespace std;

void midStream(vector<int> &data)
{
    priority_queue<int> maxheap;                            // 최대 힙을 만듭니다.
    priority_queue<int, vector<int>, greater<int>> minheap; // 최소 힙을 만듭니다.

    vector<int> ret; // 결과를 저장할 벡터

    maxheap.push(data[0]);  // 원소가 하나일 때는 최대 힙에 삽입
    ret.push_back(data[0]); // 첫 번째 원소를 중간값 결과로 삽입
    for (int i = 1; i < data.size(); i++)
    {
        if (i % 2) // 인덱스 홀수일 때, 개수 기준으로 짝수
        {
            if (maxheap.top() > data[i]) // 현재 값이 최대 힙의 최댓값보다 작으면
            {
                minheap.push(maxheap.top()); // 최대 힙의 최댓값을 값을 최소 힙에 넣고
                maxheap.pop();               // 최대 힙에서 최댓값 꺼내기
                maxheap.push(data[i]);       // 최대 힙에 현재값 넣기
            }
            else
            {
                minheap.push(data[i]); // 최소 힙에 현재 값 넣기
            }
            // 최댓값과 최솟값의 평균을 구하여 결과에 넣습니다.
            // 소수 첫 째 자리 반올림을 위해 1을 더하고 2로 나눕니다.
            ret.push_back((maxheap.top() + minheap.top() + 1) / 2);
        }
        else // 홀수
        {
            if (minheap.top() < data[i]) // 현재 값이 최소 힙의 최솟값보다 크면
            {
                maxheap.push(minheap.top()); // 최소 힙의 최솟값을 값을 최대 힙에 넣고
                minheap.pop();               // 최대 힙에서 최댓값 꺼내기
                minheap.push(data[i]);       // 최소 힙에 현재값 넣기
            }
            else
            {
                maxheap.push(data[i]); // 최대 힙에 현재 값 넣기
            }
            // 최댓값을 결과에 넣습니다.
            ret.push_back(maxheap.top());
        }
    }

    for (int i : ret)
        cout << i << ", ";
    cout << endl;
}

int main()
{
    vector<int> data = {10, 8, 7, 9, 6};
    midStream(data);

    return 0;
}