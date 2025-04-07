#include <iostream>

using namespace std;

struct Node // 단일 연결 리스트의 노드
{
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

double mean(Node* head) 
{
    int sum(0), count(0); // 평균을 구하기 위한 합과 개수

    Node* cur = head;
    while (cur != nullptr) // 리스트의 끝까지 반복
    {
        sum += cur->val;
        count++;
        cur = cur->next;
    }

    // 실수 출력을 위해 double형으로 캐스팅
    return (double)sum / count; 
}

int main() 
{
    // 1->2->3->4의 단일 연결 리스트 생성
    Node n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    
    cout << mean(&n1) << endl;

    return 0;
}

