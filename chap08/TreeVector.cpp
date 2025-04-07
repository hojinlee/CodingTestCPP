#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
private:
    int m_value;
    int m_index; // 노드 자신의 인덱스
    int m_left;  // 왼쪽 자식의 인덱스
    int m_right; // 오른쪽 자식의 인덱스

public:
    Node() : m_value(0), m_index(-1), m_left(-1), m_right(-1) {}
    Node(int value) : m_value(value), m_index(-1), m_left(-1), m_right(-1) {}

    void setIndex(int index) { m_index = index; } // 노드 자신의 인덱스로 설정
    void setLeft(int index) { m_left = index; }   // 왼쪽 자식의 인덱스로 설정
    void setRight(int index) { m_right = index; } // 오른쪽 자식의 인덱스로 설정

    int getIndex() { return m_index; }
    int getLeft() { return m_left; }
    int getRight() { return m_right; }
    int getValue() { return m_value; }
};

class Tree
{
private:
    vector<Node *> m_nodes; // 벡터를 사용하여 트리 내부 노드 관리

public:
    Tree(int size) { m_nodes.resize(size); } // 트리의 크기에 맞게 벡터 크기를 조정

    // 노드를 트리에 삽입 parent가 null이면 root
    // isLeft가 true면 부모의 왼쪽 자식, false면 오른쪽 자식
    void insert(Node *parent, Node *cur, bool isLeft)
    {
        if (!parent)
        {
            m_nodes[0] = cur; // cur가 root 노드
            cur->setIndex(0);
        }
        else
        {
            // 인덱스는 0-based 라서 2를 곱해서 자식의 인덱스를 구하기 위해서는
            // 먼저 +1을 해서1-based로 바꿔준 후 2를 곱합니다.
            int index = (parent->getIndex() + 1) * 2; // 오른쪽 자식의 인덱스입니다.
            if (isLeft)
            {
                index--; // 왼쪽 자식의 인덱스는 오른쪽에서 1감소합니다.
                parent->setLeft(index);
            }
            else
            {
                parent->setRight(index);
            }
            cur->setIndex(index);
            m_nodes[index] = cur;
        }
    }

    // 트리를 순회하며 모든 노드의 값을 출력합니다.
    void showTree(Node *root)
    {
        queue<Node *> qNode; // 너비우선탐색으로 노드의 값을 출력하기 위해 큐 생성
        qNode.push(root);

        while (!qNode.empty()) // 큐가 빌 때까지 순회
        {
            Node *cur = qNode.front();
            qNode.pop();

            const int nLeft = cur->getLeft(); // 왼쪽 자식의 인덱스를 가져옵니다.
            if (nLeft > 0)
            {
                Node *pLeft = m_nodes[nLeft];
                qNode.push(pLeft); // 왼쪽 자식을 큐에 삽입
            }

            const int nRight = cur->getRight(); // 오른쪽 자식의 인덱스를 가져옵니다.
            if (nRight > 0)
            {
                Node *pRight = m_nodes[nRight];
                qNode.push(pRight); // 오른쪽 자식을 큐에 삽입
            }

            cout << cur->getValue() << endl; // 0, 1, 2 순으로 출력합니다.
        }
    }
};

int main()
{
    Node root(0); // 0 값을 가지는 루트 노드 생성
    Node n1(1);   // 1 값을 가지는 노드 생성
    Node n2(2);   // 2 값을 가지는 노드 생성

    Tree tree(100);

    tree.insert(nullptr, &root, true);
    tree.insert(&root, &n1, true);  // n1을 루트의 왼쪽 자식으로 설정
    tree.insert(&root, &n2, false); // n2을 루트의 오른쪽 자식으로 설정

    tree.showTree(&root); // 0, 1, 2 순으로 출력합니다.

    return 0;
}