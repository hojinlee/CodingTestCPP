#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 긴 교대 부분 배열의 길이를 반환
int longest_alternate_subarray(const vector<int>& nums)
{
    const int N = nums.size();
    if(N == 0) return 0; // 입력 크기가 0이면 

    int inc(1), dec(1); // 증가할 때의 길이와 감소할 때의 길이
    
    for(int i = 1; i < N; i++)
    {
        if(nums[i - 1] < nums[i]) // 현재 값이 직전 값보다 클 때
        {
            inc = dec + 1;
        }
        else if(nums[i - 1] > nums[i])
        {
            dec = inc + 1;
        }
    }
    
    return max(inc, dec);
}

int main()
{
    cout << longest_alternate_subarray({}) << endl;    
    cout << longest_alternate_subarray({1}) << endl;        
    cout << longest_alternate_subarray({11, 10, 12, 15, 13, 3, 2, 4}) << endl;
    
    return 0;
}