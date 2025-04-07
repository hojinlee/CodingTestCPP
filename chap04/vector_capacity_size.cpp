#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(5); // 크기가 5인 int형 vector 생성
	// 5, 5 (현재 크기와 할당된 용량 출력)
	cout << v.size() << ", " << v.capacity() << endl;

	v.resize(6); // 크기를 6으로 변경
	// 6, 10 (크기가 6으로 변경되고, 용량이 자동으로 증가하여 10으로 변경됨)
	cout << v.size() << ", " << v.capacity() << endl;

	v.resize(7); // 크기를 7으로 변경
	// 7, 10 (크기가 7으로 변경되고, 용량은 이미 충분하므로 변경되지 않음)
	cout << v.size() << ", " << v.capacity() << endl;

	v.resize(4); // 크기를 4로 변경
	// 4, 10 (크기가 4로 변경되고, 용량은 그대로 유지됨)
	cout << v.size() << ", " << v.capacity() << endl;

	vector<double> v2(5); // 크기가 5인 double형 vector 생성
	// 5, 5 (현재 크기와 할당된 용량 출력)
	cout << v2.size() << ", " << v2.capacity() << endl;

	return 0;
}