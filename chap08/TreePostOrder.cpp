#include <iostream>
#include <queue>
using namespace std;

class Node
{
private:
    int m_value;// 노드의 값
    Node* m_left;
    Node* m_right;
public:
    Node() : m_value(0), m_left(nullptr), m_right(nullptr) {}
    Node(int value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
    void setLeft(Node* node) { m_left = node; }
    void setRight(Node* node) { m_right = node; }
    Node* getLeft() { return m_left; }
    Node* getRight() { return m_right; }
    int getValue() { return m_value;  }
};

void postOrder(Node* cur)
{
    if (cur)
    {
        postOrder(cur->getLeft());        // 후위 순회 순서1: 왼쪽 하위 트리
        postOrder(cur->getRight());       // 후위 순회 순서2: 오른쪽 하위 트리
        cout << cur->getValue() << endl;  // 후위 순회 순서3: 현재 노드
    }
}

int main()
{
    Node root(5);// 5 값을 가지는 루트 노드 생성
    Node n1(3); // 3 값을 가지는 노드 생성
    Node n2(7); // 7 값을 가지는 노드 생성
    root.setLeft(&n1); // n1을 루트의 왼쪽 자식으로 설정
    root.setRight(&n2); // n2을 루트의 오른쪽 자식으로 설정
    Node n3(2);
    Node n4(4);
    n1.setLeft(&n3); // n3를 n1의 왼쪽 자식으로 설정
    n1.setRight(&n4); // n4를 n1의 오른쪽 자식으로 설정
    /*
    * 다음과 같은 트리 생성
    *            5
    *           / |
    *          3  7
    *         /|
    *        2 4
    */

    postOrder(&root); // 2, 4, 3, 7, 5 순으로 출력합니다.

    return 0;
}