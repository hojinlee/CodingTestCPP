#include <iostream>
#include <stack>
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

void preOrder_iter(Node *cur)
{
    stack<Node *> stk; // 재귀를 대신하기 위해 스택 컨테이너를 사용합니다.
    if (cur)
    {
        stk.push(cur);
        while (!stk.empty())
        {
            cur = stk.top();
            cout << cur->getValue() << endl; // 전위 순회 순서1: 현재 노드
            stk.pop();

            // 순서가 바뀌는 스택의 특성상, 오른쪽을 먼저 삽입해서 나중에 순회하도록
            if (cur->getRight()) // 전위 순회 순서3: 오른쪽 하위 트리
                stk.push(cur->getRight());
            if (cur->getLeft()) // 전위 순회 순서2: 왼쪽 하위 트리
                stk.push(cur->getLeft());
        }
    }
}

int main()
{
    Node root(5);       // 5 값을 가지는 루트 노드 생성
    Node n1(3);         // 3 값을 가지는 노드 생성
    Node n2(7);         // 7 값을 가지는 노드 생성
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

    preOrder_iter(&root);

    return 0;
}
