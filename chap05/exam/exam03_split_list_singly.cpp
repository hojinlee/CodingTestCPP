#include <iostream>
using namespace std;

struct Node // 단일 연결 리스트의 노드
{
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

// head1과 head2는 함수 내부에서 포인터 값을 할당하기 위해 이중 포인터입니다.
void split_list_singly(Node* head, Node** head1, Node** head2) 
{
    // 빈 리스트라면
    if(head == nullptr) 
    {
        *head1 = nullptr;
        *head2 = nullptr;
        return;
    }

    Node* slow = head; // 한 칸씩 이동하는 느린 포인터
    Node* fast = head->next; // 두 칸씩 이동하는 빠른 포인터

    // fast를 끝까지 이동하면 slow는 리스트의 중간에 위치
    while (fast && fast->next) 
    {
        slow = slow->next; // slow는 한 칸만 이동
        fast = fast->next->next; // fast는 두 칸 이동
    }

    *head1 = head;
    *head2 = slow->next;
    slow->next = nullptr; // 두 리스트틀 나누기 위해 slow의 다음에 널값을 설정
}

int main() 
{
    // 1->2->3->4의 단일 연결 리스트 생성
    Node n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    
    // 같은 크기의 2 리스트의 머리 노드
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    split_list_singly(&n1, &head1, &head2);

    // 첫번째 리스트를 출력
    Node* cur = head1;
    while (cur != nullptr) 
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 두번째 리스트를 출력
    cur = head2;
    while (cur != nullptr) 
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}

