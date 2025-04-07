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

// 이진 탐색 트리에서 최솟값 구하기
int min_bst(Node *cur)
{
    if (!cur) // 현재 노드가 null이면 0을 반환
        return 0;

    if (cur)
    {
        // 트리의 가장 왼쪽 노드를 찾습니다.
        while (cur->getLeft())
            cur = cur->getLeft();
    }

    return cur->getValue();
}

// 이진 탐색 트리에서 최댓값 구하기
int max_bst(Node *cur)
{
    if (!cur) // 현재 노드가 null이면 0을 반환
        return 0;

    if (cur)
    {
        // 트리의 가장 오른쪽 노드를 찾습니다.
        while (cur->getRight())
            cur = cur->getRight();
    }

    return cur->getValue();
}

// 이진 탐색 트리에서 가장 큰 값과 작은 값의 차이 구하기
int diff_maxmin_bst(Node *cur)
{
    // 빈 트리는 0을 반환
    if (!cur)
        return 0;

    return max_bst(cur) - min_bst(cur);
}

int main()
{
    cout << diff_maxmin_bst(nullptr) << endl;

    Node root(4); // 5 값을 가지는 루트 노드 생성
    cout << diff_maxmin_bst(&root) << endl;

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
    cout << diff_maxmin_bst(&root) << endl;

    return 0;
}