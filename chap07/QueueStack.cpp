#include <iostream>
#include <stack>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define QUEUE_ERROR INT_MIN
class QueueStack
{
private:
	stack<int> m_stk1;
	stack<int> m_stk2;

public:
	QueueStack() {}

	bool isEmpty()
	{
		return m_stk1.empty() && m_stk2.empty();
	}

	int size() { return m_stk1.size() + m_stk2.size(); }

	void push(int value)
	{
		m_stk1.push(value);
	}

	int front()
	{
		if (isEmpty())
			return QUEUE_ERROR;
		if (m_stk2.empty())
		{
			while (!m_stk1.empty())
			{
				m_stk2.push(m_stk1.top());
				m_stk1.pop();
			}
		}
		return m_stk2.top();
	}

	int pop()
	{
		int ret = front();
		if (ret != QUEUE_ERROR)
		{
			m_stk2.pop();
		}

		return ret;
	}
};

int main()
{
	QueueStack myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	cout << myQueue.front() << endl; // 1
	myQueue.pop();

	myQueue.push(4);
	myQueue.push(5);
	cout << myQueue.front() << endl; // 2
	myQueue.pop();
	cout << myQueue.front() << endl; // 3
	myQueue.pop();
	cout << myQueue.front() << endl; // 4
	myQueue.pop();
	cout << myQueue.front() << endl; // 5
	myQueue.pop();

	return 0;
}