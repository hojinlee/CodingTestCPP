#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;

	Node() : value(0), next(nullptr) {}
	Node(int value) : value(value), next(nullptr) {}

	void deleteMe(Node *pPre)
	{
		pPre->next = next;
		delete this;
	}
};

class SList
{
private:
	Node head;

public:
	SList()
	{
		head.next = nullptr;
	}

	virtual ~SList()
	{
		while (head.next != nullptr)
			head.next->deleteMe(&head);
	}

	void push_next(int value, Node *pPre)
	{
		// 신규 노드 생성
		Node *pCur = new Node(value);

		// 현재 노드의 다음 포인터에 이전 노드의 다음 포인터를 연결
		pCur->next = pPre->next;

		// 현재 노드를 이전 노드의 다음 프인터에 연결
		pPre->next = pCur;
	}

	// 노드를 헤드에 삽입합니다.
	void push_front(int value)
	{
		push_next(value, &head);
	}

	void print()
	{
		Node *pCur = head.next;
		while (pCur)
		{
			cout << pCur->value << ", ";
			pCur = pCur->next;
		}
		cout << endl;
	}

	int length()
	{
		Node *pCur = head.next; // head 노드의 다음 노드부터 시작합니다.
		int count = 0;			// 노드 개수를 저장할 변수를 0으로 초기화합니다.

		// 연결 리스트의 끝에 도달할 때 까지 모든 노드를 순회하며 개수를 증가합니다.
		while (pCur != nullptr)
		{
			count++;		   // 노드의 개수를 증가시킵니다.
			pCur = pCur->next; // 다음 노드로 포인터를 이동합니다.
		}
		return count;
	}
};

int main()
{
	SList slist;
	slist.push_front(4);
	slist.push_front(3);
	slist.push_front(2);
	slist.push_front(1);
	slist.print(); // 1, 2, 3, 4,
	cout << slist.length() << endl;

	return 0;
}