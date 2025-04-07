#include <iostream>
#include <list>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define QUEUE_ERROR INT_MIN
class QueueVector
{
private:
	list<int> m_datas;

public:
	QueueVector() {}

	bool isEmpty()
	{
		return m_datas.empty();
	}

	int size() { m_datas.size(); }

	void push(int value)
	{
		m_datas.push_back(value);
	}

	int front()
	{
		if (isEmpty())
			return QUEUE_ERROR;
		return m_datas.front();
	}

	int pop()
	{
		int ret = front();
		if (ret != QUEUE_ERROR)
		{
			// m_datas.erase(m_datas.begin());
			m_datas.pop_front();
		}

		return ret;
	}

	void show()
	{
		for (int i : m_datas)
		{
			cout << i << " ";
		}
		cout << endl;
	}
};

int main()
{
	QueueVector myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.show(); // 1 2 3 4

	cout << myQueue.front() << endl; // 1
	myQueue.pop();
	myQueue.pop();
	myQueue.show(); // 3 4

	return 0;
}