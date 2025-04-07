#include <iostream>
#include <list>

using namespace std;

class PQueueList
{
private:
    list<int> m_data; // 리스트 컨테이너에 데이터를 저장

public:
    PQueueList() {}

    // 정렬을 유지할 수 있도록 새 값을 삽입합니다.
    void push(int value)
    {
        bool bInsert = false;
        // 리스트를 순회하며
        for (auto it = m_data.begin(); it != m_data.end(); it++)
        {
            if (value > *it) // 삽입하려는 값이 현재 값보다 크면
            {
                m_data.insert(it, value); // 연결 리스트에 삽입
                bInsert = true;
                break;
            }
        }

        // 삽입하려는 값이 현재 리스트의 모든 값보다 작거나 같다면 맨뒤에 삽입
        if (!bInsert)
            m_data.push_back(value);
    }

    int top()
    {
        return m_data.front(); // 리스트의 맨 앞 노드 반환
    }

    void pop()
    {
        if (m_data.empty()) // 우선순위 큐가 비었다면
            return;

        m_data.pop_front(); // 맨 앞 값 꺼내기
    }
};

int main()
{
    PQueueList pq;
    pq.push(5);
    pq.push(1);
    pq.push(7);
    pq.push(3);
    pq.push(4);

    cout << pq.top() << endl; // 7
    pq.pop();
    cout << pq.top() << endl; // 5

    return 0;
}