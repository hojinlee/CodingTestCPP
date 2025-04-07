#include <iostream>
#include <array>
#include <limits.h>

using namespace std;

#define PQUEUE_CAPACITY 100 // 우선순위 큐의 최대 크기
class PQueueArraySort
{
private:
    array<int, PQUEUE_CAPACITY> m_data; // 배열 컨테이너에 데이터를 저장
    int m_size;                         // 우선순위 큐의 크기
    int m_topIndex;                     // 최우선순위 값의 인덱스

public:
    PQueueArraySort() : m_size(0), m_topIndex(-1) {}
    void push(int value) // 우선순위 큐에 삽입, 큰 값이 맨 앞에 위치하는 내림차순으로 정렬 유지
    {
        if (m_size >= PQUEUE_CAPACITY) // 최대 크기를 초과하면
        {
            cout << "exceeded capacity" << endl; // 초과 메시지를 출력하고
            return;                              // 종료한다
        }

        if (m_topIndex == -1) // 최우선순위 값의 인덱스가 미지정일때는
            m_topIndex = 0;   // 맨 앞값으로 설정

        int i = m_topIndex; // 배열 내에서 우선순위 큐의 시작 인덱스
        while (i < m_size)  // 우선순위 큐의 범위 내에서 반복
        {
            // 삽입하려는 값이 i의 값보다 크면 중지
            if (value > m_data[i])
                break;
            i++; // 다음 값을 탐색
        }

        // 우선순위 큐의 맨 앞에 삽입하려고 할 때,
        // 최우선순위 값의 인덱스가 0보다 크다는 의미는 우선순위 큐의 앞 쪽에 빈 영역이 존재함을 의미
        if (m_topIndex > 0 && i == m_topIndex)
        {
            i--;          // 삽입 위치를 앞으로 이동
            m_topIndex--; // 최우선순위 값 인덱스도 앞으로 이동
        }
        else
        {
            // 삽입 하려는 위치 다음 값들을 한 칸씩 뒤로 이동
            for (int j = m_size; j > i; j--)
            {
                m_data[j] = m_data[j - 1];
            }
        }

        m_size++;          // 우선순위 큐의 크기를 1 증가
        m_data[i] = value; // while문에서 찾은 i의 위치에 value를 삽입
    }

    int top()
    {
        if (m_size == 0)    // 빈 우선순위 큐일 때
            return INT_MIN; // 가장 작은 정수값을 반환

        return m_data[m_topIndex]; // 배열의 첫 번째 값이 최우선순위 값
    }

    void pop()
    {
        if (m_size == 0)
            return;

        m_size--; // 우선순위 큐의 크기 감소

        if (m_size == 0)     // 모든 원소가 삭제되었다면
            m_topIndex = -1; // 최우선순위 값을 초기화
        else
            m_topIndex++; // 최우선순위 값 인덱스를 다음으로 이동
    }
};

int main()
{
    PQueueArraySort pq;
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