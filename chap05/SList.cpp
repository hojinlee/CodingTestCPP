#include <iostream>
using namespace std;

class Node
{
public:
    int value;  // 노드가 가지는 값
    Node *next; // 다음 노드를 가리키는 포인터

    // 생성자 함수
    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}

    // 노드 삭제 함수
    void deleteMe(Node *pPre)
    {
        pPre->next = next; // 이전 노드의 next 포인터를 현재 노드의 next 포인터로 변경
        delete this;       // 현재 노드 삭
    }
};

class SList
{
private:
    Node head; // 리스트의 시작을 가리키는 더미 노드

public:
    SList()
    {
        head.next = nullptr;
    }

    virtual ~SList() // 소멸자 함수
    {
        // 리스트를 순회하며 모든 노드를 삭제
        while (head.next != nullptr)
            head.next->deleteMe(&head);
    }

    // 노드를 특정 노드 다음에 삽입하는 함수
    void push_next(int value, Node *pPre)
    {
        // 신규 노드 생성
        Node *pCur = new Node(value);

        // 현재 노드의 다음 포인터에 이전 노드의 다음 포인터를 연결
        pCur->next = pPre->next;

        // 현재 노드를 이전 노드의 다음 포인터에 연결
        pPre->next = pCur;
    }

    // 노드를 헤드(리스트의 맨 앞)에 삽입합니다.
    void push_front(int value)
    {
        push_next(value, &head);
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

    return 0;
}