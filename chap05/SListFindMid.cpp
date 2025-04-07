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

	// 연결 리스트의 중간 노드를 찾는 함수
	Node *findMid()
	{
		Node *slow = head.next; // 노드를 하나씩 이동할 포인터
		Node *fast = head.next; // 노드를 두 개씩 이동할 포인터

		// fast 포인터가 연결 리스트의 끝에 도달하거나,
		// fast 포인터가 가리키는 노드의 다음 노드가 없을 때까지 반복합니다.
		while (fast->next && fast->next->next)
		{
			slow = slow->next;		 // slow 포인터는 한 노드씩 이동
			fast = fast->next->next; // fast 포인터는 두 노드씩 이동
		}

		return slow; // slow 포인터가 가리키는 노드가 중간 노드입니다.
	}
};

int main()
{
	SList slist;
	// head->1->2->4->7의 연결 리스트를 생성
	slist.push_front(7);
	slist.push_front(4);
	slist.push_front(2);
	slist.push_front(1);

	Node *pMid = slist.findMid();
	cout << pMid->next->value << endl;

	return 0;
}