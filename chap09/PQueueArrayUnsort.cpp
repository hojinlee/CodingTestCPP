#include <iostream>
#include <array>

using namespace std;

#define PQUEUE_CAPACITY 100 // 우선순위 큐의 최대 크기
class PQueueArray
{
private:
    array<int, PQUEUE_CAPACITY> m_data; // 배열 컨테이너에 데이터를 저장
    int m_size;                         // 우선순위 큐의 크기
    int m_topIndex;                     // 최우선순위 값의 인덱스

public:
    PQueueArray() : m_size(0), m_topIndex(-1) {}
    void push(int value) // 우선순위 큐에 삽입
    {
        if (m_size >= PQUEUE_CAPACITY) // 최대 크기를 초과하면
        {
            cout << "exceeded capacity" << endl; // 초과 메시지를 출력하고
            return;                              // 종료한다
        }
        m_data[m_size++] = value; // 새 값은 배열 끝에 삽입하고, 우선순위 큐의 크기를 증가한다.
        m_topIndex = -1;          // 최우선순위 값의 인덱스로 미지정을 뜻하는 -1로 설정한다.
    }

    // 최우선순위 값을 찾아서 인덱스를 저장합니다.
    void getTop()
    {
        int maxVal = m_data[0];          // 첫 번째 원소를 최댓값으로 지정하고
        m_topIndex = 0;                  // 최우선순위 인덱스로 첫 번째 원소로 지정한다
        for (int i = 1; i < m_size; i++) // 배열을 순회하면서
        {
            if (m_data[i] > maxVal) // 더 큰 값을 찾으면
            {
                maxVal = m_data[i]; // 값을 교체하고
                m_topIndex = i;     // 인덱스를 교체한다
            }
        }
    }

    int top()
    {
        if (m_topIndex == -1)
            getTop();

        return m_data[m_topIndex];
    }

    void pop()
    {
        if (m_size == 0)
            return;

        if (m_topIndex == -1)
            getTop();

        // 최우선순위의 원소가 여러 개일 때 선입선출로 처리하기 위해
        // 데이터를 꺼낸 위치로 모든 원소를 왼쪽으로 한칸씩 이동합니다.
        for (int i = m_topIndex; i < m_size - 1; i++)
        {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
        m_topIndex = -1;
    }
};

int main()
{
    PQueueArray pq;
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