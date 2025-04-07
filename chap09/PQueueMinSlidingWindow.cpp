#include <iostream>
#include <queue> // priority_queue
#include <vector>

using namespace std;

// 슬라이딩 윈도우에서 최솟값 구하기
void minSlidingWindow(vector<int> &data, int k)
{
    vector<int> ret;
    typedef pair<int, int> pi;                           // 첫 번째는 값, 두 번째는 인덱스
    priority_queue<pi, vector<pi>, greater<pi>> minheap; // 최소힙을 만듭니다.

    for (int i = 0; i < data.size(); i++)
    {
        minheap.push({data[i], i}); // 최소 힙에 값과 인덱스를 삽입
        if (i >= k - 1)             // 최소 힙에 k개의 원소가 있으면
        {
            pi top_candidate = minheap.top(); // 최솟값을 결과 후보로 저장
            // 힙에 들어있는 원소가 k범위밖이면 제거합니다.
            while (i - top_candidate.second >= k)
            {
                minheap.pop();                 // 최소힙에서 제거
                top_candidate = minheap.top(); // 다음 작은 값을 결과 후보로
            }
            ret.push_back(top_candidate.first);
        }
    }

    for (int i : ret)
        cout << i << ", "; // 결과 출력
    cout << endl;
}

int main()
{
    vector<int> data = {1, 4, 2, 3, 1, 5};
    minSlidingWindow(data, 3);

    return 0;
}