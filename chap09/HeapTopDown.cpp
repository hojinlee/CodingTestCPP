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

public:
    // 벡터로 초기화하는 복사 생성자
    maxheap(vector<int> &datas) : m_nodes(datas) {}

    int getSize() { return m_nodes.size(); } // 힙의 크기 구하기

    void push(int value) // 원소를 삽입하고 힙으로 만들기
    {
        m_nodes.push_back(value);     // 배열에 삽입
        _shiftUp(m_nodes.size() - 1); // 삽입한 원소를 힙으로 구성하기
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
    heap.showTree(); //  5,7,3,6,1,2,8,9,
    heap.heapify();
    heap.showTree(); //  9,8,7,6,1,2,3,5,
    heap.push(10);
    heap.showTree(); //  9,8,7,6,1,2,3,5,
    return 0;
}