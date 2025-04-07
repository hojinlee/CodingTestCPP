#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxheap
{
private:
    vector<int> m_nodes;

    // 인덱스를 사용하여 노드를 삽입하고 부모 노드와 비교하여
    // 힙 속성에 맞게 신규 노드를 위로 올리며, 클래스의 내부에서만 사용합니다.
    void _shiftUp(int cur)
    {
        while (cur > 0) // 현재 노드가 루트보다 아래에 있을 때만 처리합니다.
        {
            int parent = (cur - 1) / 2; // 부모 노드의 인덱스 구하기

            if (m_nodes[parent] > m_nodes[cur]) // 부모 노드 > 자식 노드이면
                return;                         // 종료

            swap(m_nodes[parent], m_nodes[cur]); // 부모 노드 < 자식 노드이므로 교환
            cur = parent;                        // 현재 노드를 부모 노드로 설정합니다.
        }
    }

    // 힙에서 루트 삭제 과정에서 아래 쪽으로 노드를 이동하며 힙을 만듭니다.
    void _shiftDn(int cur)
    {
        while (cur < m_nodes.size()) // 루트에서 아래로 현재 노드를 이동하며 순회합니다.
        {
            int parent = (cur - 1) / 2;
            int left = 2 * cur + 1;
            int right = left + 1;
            int next = left;
            if (left >= m_nodes.size()) // 왼쪽 자식이 없다면 그만둔다.
                break;

            if (right < m_nodes.size()) // 오른쪽 자식도 있으면 두 자식 중 큰 자식과 비교합니다.
            {
                if (m_nodes[right] > m_nodes[left])
                    next = right;
            }

            // 현재 노드가 큰 자식 노드와 같거나 크면 더이상 진행하지 않습니다.
            if (m_nodes[cur] >= m_nodes[next])
                break;

            swap(m_nodes[cur], m_nodes[next]); // 현재 노드와 다음 노드를 교환
            cur = next;
        }
    }

public:
    // 벡터로 초기화하는 복사 생성자
    maxheap(vector<int> &datas) : m_nodes(datas) {}

    int getSize() { return m_nodes.size(); } // 힙의 크기 구하기

    void push(int value) // 원소를 삽입하고 힙으로 만들기
    {
        m_nodes.push_back(value);     // 배열에 삽입
        _shiftUp(m_nodes.size() - 1); // 삽입한 원소를 힙으로 구성하기
    }

    void pop()
    {
        // 루트와 마지막 노드를 교환합니다.
        swap(m_nodes.front(), m_nodes.back());

        // 원래의 루트를 삭제합니다.
        m_nodes.pop_back();

        // 루트에서 아래로 내려가며 힙을 만듭니다.
        _shiftDn(0);
    }

    void heapify()
    {
        // 노드를 하나씩 순회하여 힙을 구성
        for (int i = 0; i < m_nodes.size(); i++)
        {
            _shiftUp(i);
        }
    }

    void showTree()
    {
        for (auto &node : m_nodes)
        {
            cout << node << ",";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> datas = {5, 7, 3, 6, 1, 2, 8, 9};
    maxheap heap(datas);
    heap.showTree(); // 5, 7, 3, 6, 1, 2, 8, 9,
    heap.heapify();
    heap.showTree(); // 9, 8, 7, 6, 1, 2, 3, 5,
    heap.pop();
    heap.showTree(); // 8, 6, 7, 5, 1, 2, 3,

    return 0;
}