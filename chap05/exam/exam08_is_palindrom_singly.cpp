#include <iostream>

using namespace std;

struct Node // 단일 연결 리스트의 노드
{
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

bool is_palindrome(Node* head) 
{
    // 빈 리스트거나 하나의 노드만 있다면 회문
    if(head == nullptr || head->next == nullptr) 
    {
        return true;
    }

    Node* slow = head; // 한 칸씩 이동하는 느린 포인터
    Node* fast = head; // 두 칸씩 이동하는 빠른 포인터

    // 리스트의 중간 노드를 찾습니다.
    while (fast && fast->next) 
    {
        slow = slow->next; // slow는 한 칸만 이동
        fast = fast->next->next; // fast는 두 칸 이동
    }

    // 리스트의 중간 지점부터 나머지 노드를 뒤집습니다.
    Node *prev = nullptr, *cur = slow;
    while(cur)
    {
        Node* next = cur->next;
        cur->next = prev; // 현재 노드의 다음 포인터로 이전 노드를 지정
        prev = cur; // 현재 노드를 다음 반복문에서 이전 노드로 사용하도록 설정
        cur = next; // 현재 노드의 다음 노드를 현재 노드로 설정
    }

    while(prev) 
    {
        if(head->val != prev->val)
            return false;

        head = head->next;
        prev = prev->next;
    }

    return true;
}

int main() 
{
    {
        // 1->2->3->2->1 단일 연결 리스트
        Node n1(1), n2(2), n3(3), n4(2), n5(1);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        cout << is_palindrome(&n1) << endl;
    }

    {
        // 1->2-3->3->2->1 단일 연결 리스트
        Node n1(1), n2(2), n3(3), n4(3), n5(2), n6(1);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;        
        cout <<  is_palindrome(&n1) << endl;
    }

    {
        // 1->2-3->3->1 단일 연결 리스트
        Node n1(1), n2(2), n3(3), n4(3), n5(1);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        cout <<  is_palindrome(&n1) << endl;
    }

    {
        // 1->2->1->1 단일 연결 리스트
        Node n1(1), n2(2), n3(1), n4(1);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        cout <<  is_palindrome(&n1) << endl;
    }

    return 0;
}


