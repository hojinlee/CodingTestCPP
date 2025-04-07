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
    void setValue(int value) { m_value = value; }
    int getValue() { return m_value; }
};

// 두 트리가 동일한지 재귀적으로 확인
int is_same_tree(Node *tree1, Node *tree2)
{
    // 두 트리가 다 비었다면 true를 반환
    if ((tree1 == nullptr) && (tree2 == nullptr))
        return 1;

    if (tree1 == nullptr) // tree1 하나만 비었다면
        return 0;

    if (tree2 == nullptr) // tree2 하나만 비었다면
        return 0;

    // 두 트리의 현재 노드 값이 다르면
    if (tree1->getValue() != tree2->getValue())
        return 0;

    return is_same_tree(tree1->getLeft(), tree2->getLeft()) && // 두 트리의 왼쪽 하위 트리가 동일한지
           is_same_tree(tree1->getRight(), tree2->getRight()); // 두 트리의 오른쪽 하위 트리가 동일한지
}

int main()
{

    Node root1(5);       // 5 값을 가지는 루트 노드 생성
    Node n1(3);          // 3 값을 가지는 노드 생성
    Node n2(7);          // 7 값을 가지는 노드 생성
    root1.setLeft(&n1);  // n1을 루트의 왼쪽 자식으로 설정
    root1.setRight(&n2); // n2을 루트의 오른쪽 자식으로 설정
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
    Node root2(5);       // 5 값을 가지는 루트 노드 생성
    Node n5(3);          // 3 값을 가지는 노드 생성
    Node n6(7);          // 7 값을 가지는 노드 생성
    root2.setLeft(&n5);  // n5를 루트의 왼쪽 자식으로 설정r
    root2.setRight(&n6); // n6을 루트의 오른쪽 자식으로 설정
    Node n7(2);
    Node n8(4);
    n5.setLeft(&n7);  // n7을 n5의 왼쪽 자식으로 설정
    n5.setRight(&n8); // n8을 n5의 오른쪽 자식으로 설정

    cout << is_same_tree(&root1, &root2) << endl;

    Node n9(5);
    n6.setLeft(&n9); // n9을 n6의 왼쪽 자식으로 설정
    cout << is_same_tree(&root1, &root2) << endl;

    return 0;
}