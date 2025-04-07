#include <iostream>
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

// 현재 노드에서 하위 트리의 높이를 반환, 입력값으로 전달한 diameter 변수에 이진 트리의 지름을 갱신
int get_diameter(Node *cur, int &diameter)
{
    // 재귀 종료 조건: 트리가 비어 있을 때
    if (cur == nullptr)
        return 0;

    int left = get_diameter(cur->getLeft(), diameter);   // 왼쪽 하위 트리의 높이 구하기
    int right = get_diameter(cur->getRight(), diameter); // 오른쪽 하위 트리의 높이 구하기

    // 현재 노드를 지나는 지름 구하기
    int cur_diameter = left + right + 1;    // 하위 노드의 높이에 현재 노드의 개수인 1을 더함
    diameter = max(cur_diameter, diameter); // 지금까지 구한 지름과 비교해서 가장 큰 값으로 갱신

    // 하위 트리의 높이를 반환
    return max(left, right) + 1;
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
    Node n5(1);
    n3.setLeft(&n5);
    /*
     * 다음과 같은 트리 생성
     *            5
     *           / |
     *          3  7
     *         /|
     *        2 4
     *       /
     *      1
     */

    int diameter = 0;
    get_diameter(&root, diameter);
    cout << diameter << endl;

    return 0;
}