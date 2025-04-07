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

	void reverse()
	{
		Node *pCur = head.next; // 현재 노드를 head 다음 노드로 초기화합니다.
		Node *pPrev = nullptr;	// 이전 노드를 가리키는 포인터를 초기화합니다.
		Node *pTemp = nullptr;	// 노드 교환에 사용할 임시 노드 포인터를 초기화합니다.

		// pCur이 nullptr가 아닐 때까지 반복합니다.
		while (pCur != nullptr)
		{
			pTemp = pCur->next; // 현재 노드의 다음 노드를 임시 노드에 저장합니다.
			pCur->next = pPrev; // pCur의 다음 포인터로 이전 노드를 가리키게 합니다.
			pPrev = pCur;		// 이전 노드를 현재 노드로 바꿉니다.

			if (pTemp != nullptr) // 다음 노드가 nullptr이 아니면 다음 노드로 이동
				pCur = pTemp;
			else // 다음 노드가 nullptr이면 루프를 종료
				break;
		}

		head.next = pCur; // head 노드의 다음 노드를 pCur로 설정합니다.
	}
};

int main()
{
	SList slist;
	// head->1->2->3->4의 연결 리스트를 생성
	slist.push_front(4);
	slist.push_front(3);
	slist.push_front(2);
	slist.push_front(1);
	slist.print(); // 1, 2, 3, 4,
	slist.reverse();
	slist.print(); // 4, 3, 2, 1,

	return 0;
}
