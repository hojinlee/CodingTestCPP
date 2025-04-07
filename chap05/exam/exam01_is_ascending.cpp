#include <iostream>
#include <limits.h>

using namespace std;

struct Node // 단일 연결 리스트의 노드
{
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

bool is_ascending(Node *head)
{
    // 빈 리스트라면
    if (head == nullptr)
    {
        return true;
    }

    Node *cur = head;
    // 이전 값의 초기값으로 정수 중 가장 작은 값으로 설정
    int prev = INT_MIN;

    while (cur != nullptr) // 리스트의 끝까지 순회
    {
        if (cur->val < prev)
            return false;
        prev = cur->val; // 현재 값을 이전 값으로 설정
        cur = cur->next;
    }

    return true;
}

int main()
{
    // 1->2->3의 단일 연결 리스트 생성
    Node n1(1), n2(2), n3(3);
    n1.next = &n2;
    n2.next = &n3;

    cout << is_ascending(&n1) << endl;

    // 1->2->3->2의 단일 연결 리스트
    Node n4(2);
    n3.next = &n4;
    cout << is_ascending(&n1) << endl;

    return 0;
}
