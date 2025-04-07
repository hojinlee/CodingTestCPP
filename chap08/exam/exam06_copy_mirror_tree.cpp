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
    Node() : m_value(0), m_left(nullptr), m_right(nullptr) {}
    Node(int value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
    void setLeft(Node *node) { m_left = node; }
    void setRight(Node *node) { m_right = node; }
    Node *getLeft() { return m_left; }
    Node *getRight() { return m_right; }
    int getValue() { return m_value; }
};

// 트리를 순회하며 모든 값을 출력합니다.
void showTree(Node *root)
{
    // 너비우선탐색으로 노드의 값을 출력하기 위해 큐를 사용
    queue<Node *> qNode;
    qNode.push(root);

    while (!qNode.empty()) // 큐가 빌 때까지 순회
    {
        Node *cur = qNode.front();
        qNode.pop();
        Node *pLeft = cur->getLeft();
        Node *pRight = cur->getRight();
        if (pLeft)
            qNode.push(pLeft); // 왼쪽 자식을 큐에 삽입
        if (pRight)
            qNode.push(pRight); // 오른쪽 자식을 큐에 삽입

        cout << cur->getValue() << endl; // 0, 1, 2 순으로 출력합니다.
    }
}

Node *copy_mirror_tree(Node *cur)
{
    Node *copy(nullptr); // 복사한 노드
    if (cur)
    {
        // 현재 노드의 값으로 새 노드를 만듭니다.
        copy = new Node(cur->getValue());
        if (copy) // 노드가 정상적으로 생성되었다면
        {
            // 현재 노드의 오른쪽 하위트리로 복사 노드의 왼쪽 하위트리를 구성
            copy->setLeft(copy_mirror_tree(cur->getRight()));
            // 현재 노드의 왼쪽 하위트리로 복사 노드의 오른쪽 하위트리를 구성
            copy->setRight(copy_mirror_tree(cur->getLeft()));
        }
    }

    return copy;
}

int main()
{
    Node root(5);       // 8 값을 가지는 루트 노드 생성
    Node n1(3);         // 6 값을 가지는 노드 생성
    Node n2(7);         // 9 값을 가지는 노드 생성
    root.setLeft(&n1);  // n1을 루트의 왼쪽 자식으로 설정
    root.setRight(&n2); // n2을 루트의 오른쪽 자식으로 설정
    Node n3(2);
    Node n4(4);
    n1.setLeft(&n3);  // n3를 n1의 왼쪽 자식으로 설정
    n1.setRight(&n4); // n4를 n1의 오른쪽 자식으로 설정
    /*
     * 다음과 같은 트리 생성
     *            5
     *           / |
     *          3  7
     *         /|
     *        2 4
     */

    Node *copy = copy_mirror_tree(&root);
    showTree(copy);

    return 0;
}