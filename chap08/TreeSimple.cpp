#include <iostream>
#include <queue>
using namespace std;

class Node
{
private:
    int m_value; // 노드의 값
    Node *m_left;
    Node *m_right;

public:
    // 노드의 기본 생성자
    Node() : m_value(0), m_left(nullptr), m_right(nullptr) {}
    // 노드의 복사 생성자
    Node(int value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
    // 왼쪽 자식 설정
    void setLeft(Node *node) { m_left = node; } 
    // 오른쪽 자식 설정
    void setRight(Node *node) { m_right = node; }
    // 왼쪽 자식 구하기
    Node *getLeft() { return m_left; }
    // 오른쪽 자식 구하기
    Node *getRight() { return m_right; }
    // 값 구하기
    int getValue() { return m_value; }
};

// 트리를 순회하면 모든 값을 출력합니다.
void showTree(Node *root)
{
    // 너비우선탐색으로 노드의 값을 출력하기 위해 큐를 사용
    queue<Node *> qNode; 
    qNode.push(root);

    while (!qNode.empty()) // 큐가 빌 때까지 순회
    {
        Node* cur = qNode.front();
        qNode.pop();
        Node* pLeft = cur->getLeft();
        Node* pRight = cur->getRight();
        if (pLeft) qNode.push(pLeft); // 왼쪽 자식을 큐에 삽입
        if (pRight) qNode.push(pRight); //오른쪽 자식을 큐에 삽입

        cout << cur->getValue() << endl; // 0, 1, 2 순으로 출력합니다.
    }
}

int main()
{
    Node root(0);       // 0 값을 가지는 루트 노드 생성
    Node n1(1);         // 1 값을 가지는 노드 생성
    Node n2(2);         // 2 값을 가지는 노드 생성
    root.setLeft(&n1);  // n1을 루트의 왼쪽 자식으로 설정
    root.setRight(&n2); // n2을 루트의 오른쪽 자식으로 설정

    showTree(&root); // 트리 내용을 출력

    return 0;
}