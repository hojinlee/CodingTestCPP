#include <iostream>
#include <stack>
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

void spiral(Node *cur)
{
    // 2개의 스택을 사용합니다.
    queue<Node *> q;
    stack<Node *> stk;

    q.push(cur);
    while (!q.empty() || !stk.empty())
    {
        // 큐에서 노드를 꺼내서 스택에 넣습니다. 왼쪽에서 오른쪽 출력
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->getValue() << endl;

            // 왼쪽에서 오른쪽으로 삽입합니다.
            if (cur->getLeft())
                stk.push(cur->getLeft());
            if (cur->getRight())
                stk.push(cur->getRight());
        }

        // 스택에서 노드를 꺼내서 큐에 넣습니다. 오른쪽에서 왼쪽 출력
        while (!stk.empty())
        {
            Node *cur = stk.top();
            stk.pop();
            cout << cur->getValue() << endl;

            // 오른쪽에서 왼쪽으로 삽입합니다.
            if (cur->getLeft())
                q.push(cur->getLeft());
            if (cur->getRight())
                q.push(cur->getRight());
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

    spiral(&root);

    return 0;
}