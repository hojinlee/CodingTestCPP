#include <iostream>
#include <vector>
using namespace std;

int find_missing_num(const vector<int>& nums)
{
    int ans(0);
    const int N = nums.size();

    for(int i = 1; i <= N + 1; i++)
    {
        ans ^= i;
    }

    for(int i = 0; i < N; i++)
    {
        ans ^= nums[i];
    }

    return ans;
}

int main()
{
    cout << find_missing_num({1, 3, 2, 5}) << endl;
    cout << find_missing_num({4, 3, 2, 5}) << endl;

    return 0;
}