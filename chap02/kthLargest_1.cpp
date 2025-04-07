#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthLargest(vector<int>& data, int k)
{
	sort(data.begin(), data.end());
	return data[data.size()-k];
}

int main() {
	vector<int> data = {3, 1, 8, 4, 2};
	cout << kthLargest(data, 2) << endl; // 4
	return 0;
}