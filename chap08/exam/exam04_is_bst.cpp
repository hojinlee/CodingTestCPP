#include <iostream>
#include <limits.h>
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

// 이진 탐색 트리 여부를 반환
int is_bst(Node *cur, int min, int max)
{
    // 빈 트리는 BST
    if (cur == nullptr)
        return 1;

    // BST가 될 수 있는 제약 조건을 벗어난 값을 가진다면
    if (cur->getValue() < min || cur->getValue() > max)
        return 0;

    // 왼쪽 하위트리가 가질 수 있는 가장 큰 값은 현재 값 - 1
    return is_bst(cur->getLeft(), min, cur->getValue() - 1) &&
           // 오른쪽 하위트리가 가질 수 있는 가장 작은 값은 현재 값 + 1
           is_bst(cur->getRight(), cur->getValue() + 1, max);
}

int main()
{
    Node root(4);       // 5 값을 가지는 루트 노드 생성
    Node n1(2);         // 3 값을 가지는 노드 생성
    Node n2(5);         // 7 값을 가지는 노드 생성
    root.setLeft(&n1);  // n1을 루트의 왼쪽 자식으로 설정
    root.setRight(&n2); // n2을 루트의 오른쪽 자식으로 설정
    Node n3(1);
    Node n4(3);
    n1.setLeft(&n3);  // n3를 n1의 왼쪽 자식으로 설정
    n1.setRight(&n4); // n4를 n1의 오른쪽 자식으로 설정
    /*
     * 다음과 같은 트리 생성
     *             4
     *           / |
     *          2  5
     *         /|
     *        1 3
     */
    cout << is_bst(&root, INT_MIN, INT_MAX) << endl;
    n4.setValue(6);
    /*
     * 다음과 같은 트리 생성
     *             4
     *           / |
     *          2  5
     *         /|
     *        1 6
     */
    cout << is_bst(&root, INT_MIN, INT_MAX) << endl;

    return 0;
}