#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 다음에 오는 큰 원소의 배열 반환
vector<int> next_greater_element(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1); // 디폴트값으로 -1
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        // 스택의 꼭대기 값보다 큰 값이 없을 때 까지 반복
        while (!s.empty() && nums[i] > nums[s.top()]) 
        {
            ans[s.top()] = nums[i]; // 큰 값을 찾으면 정답에 반영
            s.pop();
        }
        s.push(i); // 현재 값을 스택에 넣기
    }

    return ans;
}

int main()
{
    vector<int> ans = next_greater_element({3, 1, 5, 2, 2});
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
