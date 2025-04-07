#include <iostream>
using namespace std;

int getFactorialIter(int n)
{
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}

int main()
{
	cout << getFactorialIter(3) << endl;
	return 0;
}