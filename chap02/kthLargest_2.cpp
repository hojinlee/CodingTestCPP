#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargest2(vector<int>& data, int k)
{
	priority_queue<int, vector<int>, greater<int>> minheap;
	
	for(int d: data)
	{
		minheap.push(d);
		if(minheap.size() > k)
		{
			minheap.pop();
		}
	}
	
	return minheap.top();
}

int main() {
	vector<int> data = {3, 1, 8, 4, 2};
	cout << kthLargest2(data, 2) << endl; // 4
	return 0;
}