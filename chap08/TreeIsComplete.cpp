#include <iostream>
#include <queue>
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

bool isCompleteTree(Node* cur)
{
    queue<Node*> q;
    q.push(cur);

    bool hasChild = true; // 자식의 존재 여부

    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        if(cur->getLeft())
        {
            // 이전에 자식이 없는 경우가 있었다면, 다른 노드가 존재하면 완전 이진 트리가 아닙니다. 
            if(!hasChild) return false;
            q.push(cur->getLeft()); 
        }
        else
        {
            hasChild = true;
        }

        if(cur->getRight())
        {
            // 이전에 자식이 없는 경우가 있었다면, 다른 노드가 존재하면 완전 이진 트리가 아닙니다. 
            if(!hasChild) return false;
            q.push(cur->getRight()); 
        }
        else
        {
            hasChild = true;
        } 
    }

    return true;
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

    cout << isCompleteTree(&root); 

    return 0;
}