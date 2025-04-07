#include <iostream>
#include <list>

using namespace std;

class PQueueListUnsort
{
private:
    list<int> m_data; // 리스트 컨테이너에 데이터를 저장
    bool m_bValidTop; // 리스트의 맨 앞에 최우선순위 값이 존재하는지 여부

public:
    PQueueListUnsort() : m_bValidTop(false) {}
    void push(int value)
    {
        // 리스트의 뒤에 값을 삽입합니다. 따로 정렬하지 않습니다.
        m_data.push_back(value);
    }

    // 최우선순위 값을 찾아서 큐의 맨 앞에 삽입합니다.
    void getTop()
    {
        // itMax는 가장 큰 값에 대한 반복자
        list<int>::iterator itMax = m_data.begin();

        // 모든 값을 순한하면서 가장 큰 값을 가지는 노드를 찾아 itMax에 할당
        for (auto it = next(itMax, 1); it != m_data.end(); it++)
        {
            if (*it > *itMax)
            {
                itMax = it;
            }
        }

        // 가장 큰 값을 가진 노드와 맨 앞 노드를 맞 바꾸기
        swap(*m_data.begin(), *itMax);
        m_bValidTop = true; // 최우선순위 값이 정상이라고 설정
    }

    int top()
    {
        if (!m_bValidTop) // 최우선순위 값이 정상이 아닐 떄
            getTop();     // 최우선순위 값 새로 구하기

        return m_data.front(); // 리스트의 맨 앞 노드 반환
    }

    void pop()
    {
        if (m_data.empty()) // 우선순위 큐가 비었다면
            return;

        if (!m_bValidTop) // 최우선순위 값이 정상이 아닐 떄
            getTop();     // 최우선순위 값 새로 구하기

        m_data.pop_front();  // 맨 앞 값 꺼내기
        m_bValidTop = false; // 리스트의 맨 앞 노드가 최우선순위가 아니라고 설정
    }
};

int main()
{
    PQueueListUnsort pq;
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