#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class n_buffer
{
private:
    int m_capacity;     // 버퍼의 크기를 설정
    deque<int> m_deque; // 내부 자료 구조로 덱을 사용

public:
    n_buffer(int capacity) // 생성자
    {
        m_capacity = capacity;
    }

    void add(int value)
    {
        if (m_deque.size() == m_capacity) // 덱의 크기가 버퍼의 용량이면
        {
            cout << m_deque.front() << endl; // 오래된 값을 출력
            m_deque.pop_front();             // 오래된 값을 제거
        }
        m_deque.push_back(value); // 새 값을 삽입
    }
};

int main()
{
    n_buffer buf(3); // 3 크기의 n 버퍼 생성
    buf.add(1);
    buf.add(2);
    buf.add(3);
    buf.add(4);
    buf.add(5);

    return 0;
}