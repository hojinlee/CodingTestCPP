#include <iostream>
#include <stack>
using namespace std;

struct node
{
    node *left;
    node *right;
    int value;
    node(int n) : value(n), left(nullptr), right(nullptr) {}
};

int getHeightIter(node *root)
{
    if (!root)
        return 0;

    stack<node *> stk_node;
    stk_node.push(root); // 스택에 루트 노드를 삽입합니다.

    stack<int> stk_height; // 높이를 저장하는 스택을 추가합니다.
    stk_height.push(1);

    int ans = 0;
    while (!stk_node.empty()) // 스택에 값이 있을 때만 처리합니다.
    {
        node *cur = stk_node.top();   // 처리할 현재 노드를 구합니다.
        stk_node.pop();               // top에서 노드를 제거합니다.
        int cur_h = stk_height.top(); // 높이를 구할 노드를 구합니다.
        stk_height.pop();             // 높이 스택의 top에서 노드를 제거합니다.

        ans = max(ans, cur_h);

        if (cur->left)
        {
            stk_node.push(cur->left);
            stk_height.push(cur_h + 1); // 높이를 하나 증가합니다.
        }

        if (cur->right)
        {
            stk_node.push(cur->right);
            stk_height.push(cur_h + 1); // 높이를 하나 증가합니다.
        }
    }

    return ans;
}

int main()
{
    node root(10);
    node l1(3);
    root.left = &l1;
    node l21(4);
    l1.left = &l21;
    node r1(11);
    root.right = &r1;

    cout << getHeightIter(&root) << endl; // 3

    return 0;
}