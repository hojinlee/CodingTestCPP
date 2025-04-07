#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// k번째로 작은 부분 배열의 합을 반환하는 함수
int k_smallest_acc(const vector<int> &arr, int k)
{
    int n = arr.size();     // 입력 배열의 크기를 저장
    vector<int> acc(n + 1); // 누적 합을 저장하는 벡터를 생성
    acc[0] = 0;             // 첫 번째 누적 합을 0으로 초기화
    acc[1] = arr[0];        // 두 번째 누적 합은 첫 번째 원소와 동일

    for (int i = 2; i <= n; i++) // 모든 누적 합을 계산
        acc[i] = acc[i - 1] + arr[i - 1];

    // 부분 배열의 합을 저장하는 우선순위 큐를 생성. 가장 큰 합부터 저장
    priority_queue<int> pq;

    // 모든 부분 배열의 합을 계산
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            // i번째부터 j번째까지의 부분 배열의 합을 계산
            int cur_acc = acc[j] - acc[i - 1];

            if (pq.size() < k)    // 큐의 크기가 k보다 작으면
                pq.push(cur_acc); // 합을 큐에 넣습니다.
            else
            {
                if (pq.top() > cur_acc) // 현재 합이 큐의 가장 큰 합보다 작다면
                {
                    pq.pop();         // 가장 큰 합을 제거하고
                    pq.push(cur_acc); // 현재 합을 넣습니다.
                }
            }
        }
    }

    // k번째로 작은 합을 반환
    return pq.top();
}

int main()
{
    cout << k_smallest_acc({10, -10, 20}, 4) << endl;
    return 0;
}
