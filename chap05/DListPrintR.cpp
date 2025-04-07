#include <iostream>
using namespace std;

class Node
{
public:
	int value;

	Node *prev;
	Node *next;

	Node() : value(0), prev(nullptr), next(nullptr) {}
	Node(int value) : value(value), prev(nullptr), next(nullptr) {}

	void deleteMe()
	{
		if (prev != nullptr)
			prev->next = next;
		if (next != nullptr)
			next->prev = prev;

		delete this;
	}
};

class DList
{
private:
	Node head;
	Node tail;

public:
	DList()
	{
		head.next = &tail;
		tail.prev = &head;
	}

	virtual ~DList()
	{
		while (head.next != &tail)
			head.next->deleteMe();
	}

	void push_next(int value, Node *pPre)
	{
		// 신규 노드 생성
		Node *pCur = new Node(value);

		// 현재 노드의 이전, 다음 포인터를 연결
		pCur->next = pPre->next;
		pCur->prev = pPre;

		// 현재 노드를 이전 노드의 다음 프인터에, 다음 노드의 이전 포인터에 연결
		pPre->next = pCur;
		pCur->next->prev = pCur;
	}

	// 노드를 헤드에 삽입합니다.
	void push_front(int value)
	{
		push_next(value, &head);
	}

	void push_back(int value)
	{
		push_next(value, tail.prev);
	}

	void print()
	{
		Node *pCur = head.next;
		while (pCur != &tail)
		{
			cout << pCur->value << ", ";
			pCur = pCur->next;
		}
		cout << endl;
	}

	void printR()
	{
		Node *pCur = tail.prev; // pCur를 tail 이전 노드로 초기화합니다.
		while (pCur != &head)	// pCur가 head가 아닐 때까지 반복합니다.
		{
			cout << pCur->value << ", "; // 현재 노드의 값을 출력합니다.
			pCur = pCur->prev;			 // pCur를 이전 노드로 이동합니다.
		}
		cout << endl; // 출력이 끝난 후 줄바꿈을 출력합니다.
	}
};

int main()
{
	DList dlist;

	// head -> 2 -> 1 -> 4 -> 7 <- tail 의 이중 연결 리스트를 생성
	dlist.push_front(1);
	dlist.push_front(2);
	dlist.push_back(4);
	dlist.push_back(7);
	dlist.print();	// 2, 1, 4, 7,
	dlist.printR(); // 7, 4, 1, 2,

	return 0;
}