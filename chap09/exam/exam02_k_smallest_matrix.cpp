#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct element // 행렬의 원소 구조체
{
    int value; // 값
    int row;   // 행 인덱스
    int col;   // 열 인덱스
};

int kth_small_matrix(const vector<vector<int>> &mat, int k)
{
    int row_size = mat.size();    // 행의 크기
    int col_size = mat[0].size(); // 열의 크기

    int ans = 0;

    // element 구조체를 비교하기 위한 비교 연산자
    auto element_greater = [](const element &lhs, element &rhs)
    {
        return lhs.value > rhs.value;
    };

    priority_queue<element, vector<element>, decltype(element_greater)> pq(element_greater); // 최소 힙

    // 첫 번째 행의 모든 원소를 최소 힙에 넣습니다. k가 열 크기보다 작다면 k개만큼 넣습니다.
    for (int i = 0; i < min(col_size, k); i++)
    {
        pq.push({mat[0][i], 0, i});
    }

    for (int i = 0; i < k; i++) // k번 반복합니다.
    {
        auto top = pq.top(); // 최소 힙에서 가장
        pq.pop();            // 최소 힙에서 제거
        ans = top.value;

        int next_row = top.row + 1; // 가장 작은 값의 다음 행 인덱스

        if (next_row < row_size) // 가장 작은 값의 다음 행이 존재한다면 
        {
            // 최소 힙에서 꺼낸 원소의 다음 행에 위치한 원소를 최소 힙에 삽입
            pq.push({mat[next_row][top.col], next_row, top.col});
        }
    }

    return ans;
}

int main()
{
    cout << kth_small_matrix({{1, 2, 5}, {3, 4, 6}, {7, 8, 9}}, 7);

    return 0;
}
