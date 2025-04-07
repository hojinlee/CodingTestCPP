#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> merge_intervals(const vector<pair<int, int>> &intervals)
{
    auto comparator2 = [](const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        if (lhs.first == rhs.first)
            return lhs.second > rhs.second;

        return lhs.first > rhs.first;
    };

    // 간격을 입력으로 하는 최소 힙 생성
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &interval : intervals)
    {
        // 모든 간격을 최소 힙에 삽입
        pq.push(interval);
    }

    vector<pair<int, int>> ans;
    while (!pq.empty())
    {
        // 우선순위 큐에서 꼭대긴 간격 가져오기
        auto cur = pq.top();
        pq.pop();

        // 결과 벡터가 비어있거나, 가져온 간격의 시작점이 결과 벡터의 마지막 간격의 끝점보다 크다면,
        if (ans.empty() || cur.first > ans.back().second)
        {
            // 가져온 간격을 결과 벡터에 추가
            ans.push_back(cur);
        }
        else
        {
            // 그렇지 않으면, 가져온 간격을 결과 벡터의 마지막 간격과 병합하여 끝점을 갱신
            ans.back().second = max(ans.back().second, cur.second);
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> ans = merge_intervals({{2, 4}, {3, 6}, {5, 8}, {9, 10}});

    for (auto &interval : ans)
    {
        // 병합 결과를 출력합니다.
        cout << "{" << interval.first << ", " << interval.second << "}" << endl;
    }

    return 0;
}
