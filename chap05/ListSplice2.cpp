#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> list1; // 정수를 저장하는 리스트1 선언

	list1.push_back(1); // 리스트1에 1 추가
	list1.push_back(3); // 리스트1에 3 추가
	list1.push_back(4); // 리스트1에 4 추가

	list<int> list2;	// 정수를 저장하는 리스트2 선언
	list2.push_back(5); // 리스트2에 5 추가
	list2.push_back(2); // 리스트2에 2 추가
	list2.push_back(6); // 리스트2에 6 추가

	// 리스트1에서 리스트2의 일부 원소를 삽입하는 작업
	// 리스트1의 1번째 위치 뒤에 리스트2의 2번째 원소부터 마지막 원소 앞까지 삽입
	list1.splice(next(list1.begin(), 1), list2, ++list2.begin(), --list2.end());

	for (auto &n : list1)
		cout << n << ' '; // 1 2 3 4

	cout << endl
		 << list1.size() << ", " << list2.size(); // 4 2

	return 0;
}