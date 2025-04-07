#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void most_k_freq(vector<int> &in, int k, vector<int> &out)
{
  unordered_map<int, int> mapCount;                   // 개수를 저장할 맵
  typedef pair<int, int> pi;                          // 값-빈도의 쌍
  priority_queue<pi, deque<pi>, greater<pi>> minHeap; // 값-빈도 최소힙

  for (auto &i : in)
    mapCount[i]++; // 입력값의 빈도를 계산

  for (auto it : mapCount)
  {
    // 빈도를 우선순위로 계산하도록 순서를 바꿔서 삽입
    minHeap.push(make_pair(it.second, it.first)); // 값-빈도 쌍으로 만들어 삽입
    if (minHeap.size() > k)                       // 힙 크기가 k보다 크면
      minHeap.pop();                              // 가장 작은 값을 제거
  }

  while (!minHeap.empty()) // 힙이 비어 있지 않으면
  {
    out.push_back(minHeap.top().second); // 빈도에 대한 값을 삽입
    minHeap.pop();
  }
}

int main()
{
  vector<int> datas = {5, 4, 5, 1, 2};
  vector<int> result;
  most_k_freq(datas, 3, result);

  for (auto &i : result)
  {
    cout << i << ", "; // 2, 4, 5
  }
  cout << endl;

  return 0;
}