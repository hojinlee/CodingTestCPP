#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;

	Node() : value(0), next(nullptr) {	}
	Node(int value) : value(value) , next(nullptr){	}
	
	void deleteMe(Node* pPre)
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
		while(head .next != nullptr)
			head.next->deleteMe(&head);
	}
	
	void push_next(int value, Node* pPre)
	{
		// 신규 노드 생성
		Node* pCur = new Node(value);

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
        Node* pCur = head.next;
        while(pCur)
        {
            cout << pCur->value << ", ";
            pCur = pCur->next;
        }
        cout << endl;
    }

	void merge_sorted(SList& target)
	{
		Node* pRight = target.head.next;
		if (!pRight) return;

		Node* pLeft = head.next;
		if (!pLeft) return;

		Node ans;
		Node* pCur = &ans;

		while (pLeft && pRight)
		{
			// 작은 노드부터 결과 리스트에 삽입
			if (pLeft->value > pRight->value)
			{
				pCur->next = pRight;
				pRight = pRight->next;
			}
			else
			{
				pCur->next = pLeft;
				pLeft = pLeft->next;
			}
			pCur = pCur->next;
		}

		// 위에서 처리하지 못하고 남은 노드를 결과에 삽입
		if (pLeft) pCur->next = pLeft;
		if (pRight) pCur->next = pRight;

		// 이 코드가 없으면 target에서 deleteMe가 불릴 때 이미 delete한 메모리를 지우려고 시도하여 오류 발생합니다.
		target.head.next = nullptr;
		head.next = ans.next;
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

	SList slist2;
	// head->3->5->6->9의 연결 리스트를 생성
	slist2.push_front(9);
	slist2.push_front(6);
	slist2.push_front(5);
	slist2.push_front(3);

	slist.merge_sorted(slist2);
    slist.print(); // 1, 2, 3, 4, 5, 6, 7, 9,

	return 0;
}

