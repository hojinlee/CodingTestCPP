#include <iostream>
#include <vector>
using namespace std;

vector<int> zigzag(vector<int> nums)
{
    const int N = nums.size();
    vector<int> ans(N);
    int big(N - 1), small(0); // 큰 수와 작은 수의 인덱스 
    
    for(int i = 0; i < N; i++)
    {
        if(i & 1) // 홀수
        {
            // 작은 값을 지정하고 오른쪽으로 이동
            ans[i] = nums[small++]; 
        }
        else // 짝수
        {
            // 큰 값을 지정하고 왼쪽으로 이동
            ans[i] = nums[big--]; 
        }
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = zigzag(nums);
    for(int i: ans)
        cout << i << ',';
    cout << endl;

    return 0;
}
