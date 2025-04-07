#include <iostream>
#include <deque>

using namespace std;

class CircularQueue
{
private:
    int m_capicity; // 원형 큐의 용량
    deque<int> m_dq;

public:
    CircularQueue(int capicity) : m_capicity(capicity) {}

    bool isFull()
    {
        // 덱 사이즈가 원형 큐의 용량에 다다르면 꽉 찬 것입니다.
        if (m_dq.size() == m_capicity)
            return true;
        return false;
    }

    bool isEmpty()
    {
        // 덱 사이즈가 0이면 원형 큐가 빈 것입니다.
        if (m_dq.size() == 0)
            return true;
        return false;
    }

    bool push(int value)
    {
        // 원형 큐의 크기를 넘어서는 원소 삽입은 안됩니다.
        if (isFull())
            return false;

        m_dq.push_back(value);
        return true;
    }

    bool pop()
    {
        if (isEmpty())
            return false;
        m_dq.pop_front();
        return true;
    }

    int front()
    {
        return m_dq.front();
    }

    int back()
    {
        return m_dq.back();
    }
};

int main()
{
    CircularQueue cq(5);
    cq.push(3);
    cq.push(4);
    cq.pop();

    return 0;
}