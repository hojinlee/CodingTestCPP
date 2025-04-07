#include <iostream>
using namespace std;

struct node
{
    node *left;
    node *right;
    int value;
    node(int n) : value(n), left(nullptr), right(nullptr) {}
};

int getHeightRecur(node *root)
{
    if (!root)
        return 0;
    int ans = 1; // 현재 노드의 높이를 의미하며 1로 초기화
    ans += max(getHeightRecur(root->left), getHeightRecur(root->right));
    return ans;
}

int main()
{
    node root(10);   // 다음과 같은 이진 트리를 구성
    node l1(3);      //      10
    root.left = &l1; //     /  ╲
    node l21(4);     //    3    11
    l1.left = &l21;  //   /
    node r1(11);     //  4

    root.right = &r1;

    cout << getHeightRecur(&root) << endl; // 3

    return 0;
}