#include <iostream>
#include <vector>

using namespace std;

int find_no_pair(vector<int> &in)
{
  int result = 0; // 초기값은 모든 비트가 0인 상태로

  for (int &i : in)
  {
    // result와 i의 서로 다른 비트만 result에 남습니다.
    result ^= i; // XOR 비트 연산
  }
  return result;
}

int main()
{
  vector<int> datas = {5, 4, 5, 3, 4};
  cout << find_no_pair(datas) << endl;

  return 0;
}