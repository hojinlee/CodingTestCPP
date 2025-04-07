#include <iostream>
#include <limits.h>
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

// 트리를 순회하면 모든 값을 출력합니다.
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

        int left = cur->getLeft() == nullptr ? 0 : cur->getLeft()->getValue();
        int right = cur->getRight() == nullptr ? 0 : cur->getRight()->getValue();
        cout << cur->getValue() << ", " << left << ", " << right << endl;
    }
}

// 배열을 이진 탐색 트리로 변환
Node *array_to_bst(const int arr[], int start, int end)
{
    if (start > end) // 시작이 끝보다 크면 재귀 종료
        return nullptr;

    int mid = start + (end - start) / 2; // 중간 원소의 인덱스
    Node *root = new Node(arr[mid]);     // 중간 값으로 루트 노드 생성

    // 재귀 함수를 호출해서 루트의 왼쪽 하위 트리를 생성하여 연결
    root->setLeft(array_to_bst(arr, start, mid - 1));
    // 재귀 함수를 호출해서 루트의 오른쪽 하위 트리를 생성하여 연결
    root->setRight(array_to_bst(arr, mid + 1, end));

    return root;
}

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root = array_to_bst(arr, 0, 7);
    showTree(root);
    /*
        4
        \

    */

    return 0;
}