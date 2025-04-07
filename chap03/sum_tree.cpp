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

int sumTree(node *root)
{
    int ans = 0;
    stack<node *> stk;

    // 시작은 스택에 루트를 삽입합니다.
    stk.push(root);

    // 스택이 빌 때까지 반복합니다.
    while (!stk.empty())
    {
        // 스택의 꼭대기 원소를 꺼내 cur에 할당합니다.
        node *cur = stk.top();
        // 스택의 top()은 값을 조회만 할 뿐이므로 pop()을 호출하여 스택에서 꺼냅니다.
        stk.pop();

        ans += cur->value;
        // 노드가 널 값이 아닌 경우에만 스택에 넣습니다.
        if (cur->right)
            stk.push(cur->right);
        if (cur->left)
            stk.push(cur->left);
    }
    return ans;
}

int main()
{
    node a(100), b(10), c(20), d(5), e(3);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    cout << sumTree(&a) << endl;
    return 0;
}