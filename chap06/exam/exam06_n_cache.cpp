#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class cache
{
private:
    int m_capacity;                // 버퍼의 크기를 설정
    deque<pair<int, int>> m_deque; // 내부 자료 구조로 덱을 사용

public:
    cache(int capacity) // 생성자
    {
        m_capacity = capacity;
    }

    void add(int value, int hit)
    {
        if (m_deque.size() == m_capacity) // 덱의 크기가 캐시의 용량이면
        {
            // 오래된 값과 최근 값 중 히트가 작은 값을 제거
            if (m_deque.front().second > m_deque.back().second)
            {
                cout << m_deque.back().second << endl;
                m_deque.pop_back(); // 최근 값을 제거
            }
            else
            {
                cout << m_deque.front().second << endl;
                m_deque.pop_front(); // 오래된 값을 제거
            }
            // 최근 값을 제거
        }
        m_deque.push_back({value, hit}); // 새 값을 삽입
    }
};

int main()
{
    cache c1(3); // 3 크기의 n 캐시 생성
    c1.add(1, 3);
    c1.add(2, 4);
    c1.add(3, 7);
    c1.add(4, 2);
    c1.add(5, 5);

    return 0;
}