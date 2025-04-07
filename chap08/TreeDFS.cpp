#include <iostream>
#include <stack>
using namespace std;

class Node
{
private:
    int m_value; // 노드의 값
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

void dfs(Node* cur)
{
    stack<Node*> stk;
    stk.push(cur); 
    while(!stk.empty()) // 스택이 빌 때 까지
    {
        Node* cur = stk.top();  // 스택 꼭대기에서 값 꺼내기
        stk.pop();
        cout << cur->getValue()  << endl;
        if (cur->getLeft()) stk.push(cur->getLeft()); // 왼쪽 자식을 스택에
        if (cur->getRight()) stk.push(cur->getRight()); // 오른쪽 자식을 스택에
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

    dfs(&root);

    return 0;
}