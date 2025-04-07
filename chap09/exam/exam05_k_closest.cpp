#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// 원점에서 가까운 k개의 점을 찾는 함수
vector<vector<int>> k_closest(const vector<vector<int>> &points, int k)
{
    // pair의 첫 번째 원소는 점의 거리, 두 번째 원소는 점의 좌표
    priority_queue<pair<int, vector<int>>> pq; // 최대힙

    for (const auto &point : points) // 각 점에 대해 순회
    {
        // 원점으로부터의 거리를 계산, 제곱의 합만 구하고, 제곱근을 구하지 않음
        int dist = point[0] * point[0] + point[1] * point[1];
        // 거리와 점을 pair로 만들어 힙에 추가
        pq.emplace(dist, point);

        if (pq.size() > k) // 힙의 크기가 K보다 크면,
        {
            pq.pop(); // 가장 먼 점을 제거
        }
    }

    // 결과를 담을 벡터
    vector<vector<int>> ans;
    while (!pq.empty()) // 힙에 남은 원소들을 결과 벡터에 추가
    {
        // 가장 먼 점을 결과 벡터에 추가
        ans.push_back(pq.top().second);
        // 가장 위에 있는 원소를 힙에서 제거
        pq.pop();
    }

    // 결과 반환
    return ans;
}

int main()
{
    vector<vector<int>> result = k_closest({{2, 1}, {-4, 2}, {-2, 2}, {3, 1}}, 2);

    // 결과 출력
    for (const auto &pt : result)
    {
        cout << pt[0] << ", " << pt[1] << endl;
    }

    return 0;
}
