#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int find_onlyone(vector<int>& nums)
{
  int ans = 0;
  for (int& num : nums)
  {
    ans ^= num; // bitwise xor 연산으로 값 찾기
  }

  return ans;
}

int main()
{
  vector<int> data = { 1023, -1, 999999, 2, 1023, -1, 999999 }; // 2
  cout << find_onlyone(data) << endl;
  return 0;
}
