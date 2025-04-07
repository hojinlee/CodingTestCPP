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

	Node *backN(int n)
	{
		// 느린 포인터와 빠른 포인터를 시작 노드의 다음 노드로 초기화합니다.
		Node *slow = head.next;
		Node *fast = head.next;

		// fast와 slow를 동시에 n번 이동합니다.
		// fast 포인터가 리스트 끝에 도달하거나 n이 0보다 작아질 때까지 반복합니다.
		while (fast->next && fast->next->next && n++ > 0)
		{
			slow = slow->next;		 // slow 포인터를 다음 노드로 이동합니다.
			fast = fast->next->next; // fast 포인터를 두 개의 노드씩 건너뛰어 이동합니다.
		}

		// fast 포인터를 리스트의 끝으로 이동합니다.
		while (fast) // fast 포인터가 NULL이 아닐 때까지 반복합니다.
		{
			slow = slow->next; // slow 포인터를 다음 노드로 이동합니다.
			fast = fast->next; // fast 포인터를 다음 노드로 이동합니다.
		}

		return slow; // slow 포인터를 반환합니다.
	}
};

int main()
{
	SList slist;
	// head->1->2->4->7->8의 연결 리스트를 생성
	slist.push_front(8);
	slist.push_front(7);
	slist.push_front(4);
	slist.push_front(2);
	slist.push_front(1);
	slist.print();						   // 1, 2, 4, 7, 8
	cout << slist.backN(2)->value << endl; // 7

	return 0;
}