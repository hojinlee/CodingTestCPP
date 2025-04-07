#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 가장 작은 정수값을 에러값으로 사용
#define QUEUE_ERROR INT_MIN
class QueueVector
{
private:
	vector<int> m_data;

public:
	QueueVector() {}

	bool isEmpty() // 큐가 비어 있는지
	{
		return m_data.empty();
	}

	int size() { m_data.size(); } // 큐의 크기 반환

	void push(int value) // 큐에 값 삽입
	{
		m_data.push_back(value);
	}

	int front() // 큐의 맨 앞 값 반환
	{
		if (isEmpty())
			return QUEUE_ERROR;
		return m_data[0];
	}

	int pop() // 큐의 맨 앞 값 반환하고 꺼내기
	{
		int ret = front();
		if (ret != QUEUE_ERROR)
		{
			m_data.erase(m_data.begin());
		}

		return ret;
	}

	void show() // 큐의 내용 출력
	{
		// 큐의 앞에서 뒤로 출력
		for (int i : m_data)
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
	myQueue.show();

	cout << myQueue.front() << endl;
	myQueue.pop();
	myQueue.pop();
	myQueue.show();

	return 0;
}