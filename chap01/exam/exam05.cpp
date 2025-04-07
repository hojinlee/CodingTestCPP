#include <iostream>
using namespace std;

// n은 array의 size, r은 순열의 크기
int permute(int* data, int n, int r, int depth)
{
	if (r == depth) {
		for (int i = 0; i<r; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		return 0;
	}

	for (int i = depth; i<n; i++) {
		swap(data[i], data[depth]);
		permute(data, n, r, depth + 1);
		swap(data[i], data[depth]);
	}
	return 0;
}

int main()
{
	int data[] = { 1,2,3 };
	permute(data, 3, 3, 0);

    return 0;
}