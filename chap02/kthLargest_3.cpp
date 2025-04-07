#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int partition(vector<int>& data, int left, int right)
{	
	int pivot = data[right];
	int i = left;
	for(int j = left; j <= right -1; j++)
	{
		if(data[j] <= pivot)
		{
			swap(data[i], data[j]);
			i++;
		}
	}
	swap(data[i], data[right]);
	return i;
}

int quickSelect(vector<int>& data, int k, int left, int right)
{
	if(k>0 && k <= right - left + 1)
	{
		int pos = partition(data, left, right);
		if(right - pos == k - 1)
			return data[pos];
		if(right - pos > k - 1) // 오른쪽 하위 배열에 대한 탐
			return quickSelect(data, k, pos+1, right);
			
		// 왼쪽 하위 배열에 대한 탐색	
		return quickSelect(data, k -( right - pos) -1, left, pos-1);
	}
	
	return INT_MAX;
}

int kthLargest3(vector<int>& data, int k)
{
	return quickSelect(data, k, 0, data.size()-1);
}

int main() {
	vector<int> data = {3, 1, 8, 4, 2};
	cout << kthLargest3(data, 2) << endl; // 4
	return 0;
}