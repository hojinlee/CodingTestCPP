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
	Node head; // 리스트의 시작 노드인 head
	Node tail; // 리스트의 끝 노드인 tail

public:
	DList()
	{
		head.next = &tail; // head의 다음 노드를 tail로 초기화
		tail.prev = &head; // tail의 이전 노드를 head로 초기화
	}

	virtual ~DList()
	{
		// 리스트의 모든 노드를 삭제하는 소멸자
		while (head.next != &tail) // head의 다음 노드가 tail이 아닐 때까지 반복
			head.next->deleteMe(); // head의 다음 노드를 삭제
	}

	void push_next(int value, Node *pPre)
	{
		// 신규  노드 생성
		Node *pCur = new Node(value);

		// 현재  노드의 이전, 다음 포인터를 연결
		pCur->next = pPre->next;
		pCur->prev = pPre;

		// 현재  노드를 이전 노드의 다음 포인터에, 다음 노드의 이전 포인터에 연결
		pPre->next = pCur;
		pCur->next->prev = pCur;
	}

	// 노드를 head 뒤에 삽입합니다.
	void push_front(int value)
	{
		push_next(value, &head);
	}

	// 노드를 tail 앞에 삽입합니다.
	void push_back(int value)
	{
		push_next(value, tail.prev);
	}
};

int main()
{
	DList dlist;

	// head -> 2 -> 1 -> 4 -> 7 <- tail 의 이중 연결 리스트를 생성
	dlist.push_front(1); // 1을 head 뒤에 삽입
	dlist.push_front(2); // 2를 head 뒤에 삽입
	dlist.push_back(4);	 // 4를 tail 앞에 삽입
	dlist.push_back(7);	 // 7을 tail 앞에 삽입

	return 0;
}