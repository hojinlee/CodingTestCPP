#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 밧줄을 최소 비용으로 연결하는 함수
int mincost_rope(const vector<int> &ropes)
{
    // 밧줄의 길이를 저장하는 최소 힙 생성, greater를 비교자로 지정
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes.begin(), ropes.end());

    // 총 비용을 저장할 변수
    int total_cost = 0;

    // 힙에 하나의 요소만 남을 때까지
    while (min_heap.size() > 1)
    {
        int cost = min_heap.top(); // 가장 짧은 밧줄 구해서 비용으로 
        min_heap.pop(); // 가장 짧은 밧줄 꺼내기
        
        cost += min_heap.top(); // 두 번째로 짧은 밧줄 구해서 비용에 더하기
        min_heap.pop(); // 두 번째로 짧은 밧줄 꺼내기

        // 총 비용에 추가
        total_cost += cost;

        // 연결된 밧줄을 다시 최소 힙에 추가
        min_heap.push(cost);
    }

    // 총 비용 반환
    return total_cost;
}

int main()
{
    // 모든 밧줄을 최소 비용으로 연결하고 그 비용을 출력
    cout << mincost_rope({3, 4, 5, 6}) << endl;

    return 0;
}
