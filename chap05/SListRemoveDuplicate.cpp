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

	void remove_duplicate_sorted()
	{
		Node *pCur = head.next;
		Node *pNext = nullptr;

		while (pCur != nullptr && pCur->next != nullptr)
		{
			pNext = pCur->next;
			// 중복값을 가지는 노드를 발견
			if (pCur->value == pNext->value)
			{
				pNext->deleteMe(pCur);
			}
			else
			{
				pCur = pCur->next;
			}
		}
	}
};

int main()
{
	SList slist;
	// head->1->2->2->2->3->4->4의 연결 리스트를 생성
	slist.push_front(4);
	slist.push_front(4);
	slist.push_front(3);
	slist.push_front(2);
	slist.push_front(2);
	slist.push_front(2);
	slist.push_front(1);
	slist.print(); // 1, 2, 2, 2, 3, 4, 4,
	slist.remove_duplicate_sorted();
	slist.print(); // 1, 2, 3, 4,

	return 0;
}