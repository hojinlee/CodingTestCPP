#include <iostream>
#include <vector>

using namespace std;

class maxheap
{
    private:
    vector<int> m_nodes; // 노드의 값을 벡터 컨테이너에 저장

    public:
    // 벡터로 초기화하는 복사 생성자
    maxheap(vector<int>& data) : m_nodes(data) { }

    int getSize() { return m_nodes.size(); }

    void showTree()
    {
        for (auto& node : m_nodes)
        {
            cout << node << endl; // 각 노드 값을 출력
        }
    }
};

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5 };
    maxheap heap(data); 
    heap.showTree(); // 힙의 노드 값을 출력

    return 0;
}