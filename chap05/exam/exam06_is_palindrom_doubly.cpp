#include <iostream>
using namespace std;

struct Node // 이중 연결 리스트의 노드
{
    int val;
    Node* prev;
    Node* next;
    Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

bool is_palindrome(Node* head) 
{
    // 빈 리스트거나 하나의 노드만 있다면 회문
    if(head == nullptr || head->next == nullptr) 
    {
        return true;
    }
   
    Node* tail = head;
    // 리스트의 꼬리를 찾습니다.
    while(tail->next)
    {   
        tail = tail->next;
    }
    
    // 중간 지점에서 만날 때까지 반복
    while(head != tail) 
    {
        if(head->val != tail->val)
            return false;

        head = head->next;

        // 노드의 수가 짝수일 때, 중간 지점에서 만났는지 
        if(head == tail) 
        {
            // 짝수일 때 양 노드를 비교
            if(head->val != tail->val)
                return false;
            return true;
        }
        
        tail = tail->prev;
    }

    return true;
}

int main() 
{
   {
        // 1->2->3->2->1 이중 연결 리스트
        Node n1(1), n2(2), n3(3), n4(2), n5(1);
        n1.next = &n2; n2.prev = &n1;
        n2.next = &n3; n3.prev = &n2;
        n3.next = &n4; n4.prev = &n3;
        n4.next = &n5; n5.prev = &n4;
        cout << is_palindrome(&n1) << endl;
    }

    {
        // 1->2-3->3->2->1 이중 연결 리스트
        Node n1(1), n2(2), n3(3), n4(3), n5(2), n6(1);
        n1.next = &n2; n2.prev = &n1;
        n2.next = &n3; n3.prev = &n2;
        n3.next = &n4; n4.prev = &n3;
        n4.next = &n5; n5.prev = &n4;
        n5.next = &n6; n6.prev = &n5;
        cout <<  is_palindrome(&n1) << endl;
    }

    {
        // 1->2-3->3->1 이중 연결 리스트
        Node n1(1), n2(2), n3(3), n4(3), n5(1);
        n1.next = &n2; n2.prev = &n1;
        n2.next = &n3; n3.prev = &n2;
        n3.next = &n4; n4.prev = &n3;
        n4.next = &n5; n5.prev = &n4;
        cout <<  is_palindrome(&n1) << endl;
    }

    {
        // 1->2->1->1 이중 연결 리스트
        Node n1(1), n2(2), n3(1), n4(1);
        n1.next = &n2; n2.prev = &n1;
        n2.next = &n3; n3.prev = &n2;
        n3.next = &n4; n4.prev = &n3;
        cout <<  is_palindrome(&n1) << endl;
    }

    return 0;
}

